#import "UitzendingGemistAPIClient.h"
#import "HTMLParser.h"


static NSString * const kUitzendingGemistAPIBaseURLString = @"http://www.uitzendinggemist.nl/";
static NSString * const kUitzendingGemistAPICookiesHost = @"cookies.publiekeomroep.nl";
static NSString * const kUitzendingGemistAPICookiesAcceptURLString = @"http://cookies.publiekeomroep.nl/accept/";
static NSString * const kUitzendingGemistAPIUserAgent = @"Mozilla/5.0 (iPad; CPU OS 6_0 like Mac OS X) AppleWebKit/536.26 (KHTML, like Gecko) Version/6.0 Mobile/10A5376e Safari/8536.25";


@implementation UitzendingGemistAPIClient

+ (UitzendingGemistAPIClient *)sharedClient {
    static UitzendingGemistAPIClient *_sharedClient = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedClient = [[self alloc] initWithBaseURL:[NSURL URLWithString:kUitzendingGemistAPIBaseURLString]];
    });
    
    return _sharedClient;
}

- (id)initWithBaseURL:(NSURL *)url {
    self = [super initWithBaseURL:url];
    if (!self) {
        return nil;
    }
    
    [self registerHTTPOperationClass:[AFHTTPRequestOperation class]];
    [self setDefaultHeader:@"User-Agent" value:kUitzendingGemistAPIUserAgent];
    [self setDefaultHeader:@"Accept" value:@"text/html"];
    
    return self;
}

// TODO check if cookie exists, if not start flow immediately.
- (void)getPath:(NSString *)path
     parameters:(NSDictionary *)parameters
        success:(UZGSuccessBlock)success
        failure:(UZGFailureBlock)failure;
{
  // Check if we need to go through a cookie acceptance flow. Stupid cookie law...
  UZGSuccessBlock successWrapper = ^(AFHTTPRequestOperation *operation, id data) {
    NSString *host = operation.response.URL.host;
    if ([host isEqualToString:kUitzendingGemistAPICookiesHost]) {
      [self acceptCookiesWithSuccess:success failure:failure];
    } else {
      success(operation, data);
    }
  };
  [super getPath:path
      parameters:parameters
         success:successWrapper
         failure:failure];
}

- (void)acceptCookiesWithSuccess:(UZGSuccessBlock)success
                         failure:(UZGFailureBlock)failure;
{
  NSLog(@"-------------------------------------------------------------------");
  NSLog(@"[!] START ACCEPT COOKIES PROCESS!");
  NSLog(@"-------------------------------------------------------------------");
  NSURL *URL = [NSURL URLWithString:kUitzendingGemistAPICookiesAcceptURLString];
  NSURLRequest *request = [NSURLRequest requestWithURL:URL];
  [self enqueueHTTPRequestOperation:[self HTTPRequestOperationWithRequest:request
                                                                  success:success
                                                                  failure:failure]];
}

- (void)episodesOfShowAtPath:(NSString *)showPath
                        page:(NSUInteger)pageNumber
                     success:(UZGSuccessBlock)success
                     failure:(UZGFailureBlock)failure;
{
  NSString *path = [NSString stringWithFormat:@"%@/afleveringen?page=%d", showPath, pageNumber];
  [self getPath:path parameters:nil success:^(AFHTTPRequestOperation *operation, NSData *data) {
    //NSLog(@"RESPONSE BODY: %@", [[NSString alloc] initWithData:html encoding:NSUTF8StringEncoding]);
    //NSArray *cookies = [[NSHTTPCookieStorage sharedHTTPCookieStorage] cookies];
    //for (NSHTTPCookie *cookie in cookies) {
      //NSLog(@"COOKIE: %@", cookie);
    //}

    NSError *parseError = nil;
    HTMLParser *parser = [[HTMLParser alloc] initWithData:data error:&parseError];

    if (parseError) {
      failure(operation, parseError);
    } else {
      // TODO:
      // * collect pagination info
      // * collect thumbnail url
      // * collect datetime metadata
      HTMLNode *bodyNode = [parser body];
      NSArray *epNodes = [bodyNode findChildrenOfClass:@"episode active knav"];
      NSMutableArray *episodes = [NSMutableArray new];
      for (HTMLNode *epNode in epNodes) {
        HTMLNode *anchorNode = [epNode findChildrenOfClass:@"episode active knav_link"][0];
        [episodes addObject:@{ @"title":anchorNode.contents, @"path":[anchorNode getAttributeNamed:@"href"] }];
      }
      // NSLog(@"%@", episodes);
      success(operation, episodes);
    }
  } failure:failure];
}

@end
