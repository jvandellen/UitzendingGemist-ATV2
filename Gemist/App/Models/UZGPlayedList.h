#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, UZGEpisodeProgressStatus) {
  UZGEpisodeUnplayedStatus,
  UZGEpisodeUnplayedPartialStatus,
  UZGEpisodePlayedStatus
};

@interface UZGPlayedList : NSObject

+ (UZGPlayedList *)sharedList;

- (NSDictionary *)allBookmarks;
- (void)setHasBookmarkedShow:(BOOL)bookmark forPath:(NSString *)path withTitle:(NSString *)title;
- (BOOL)hasBookmarkedShowForPath:(NSString *)path;

- (void)setPlayed:(BOOL)played forEpisodePath:(NSString *)path;
- (BOOL)playedEpisodeForPath:(NSString *)path;

- (void)setBookmarkTime:(NSUInteger)seconds forEpisodePath:(NSString *)path;
- (NSUInteger)bookmarkTimeForEpisodePath:(NSString *)path;

- (void)setDuration:(NSUInteger)seconds forEpisodePath:(NSString *)path;
- (NSUInteger)durationOfEpisodeForPath:(NSString *)path;

- (UZGEpisodeProgressStatus)playedStatusForEpisodePath:(NSString *)path;

@end
