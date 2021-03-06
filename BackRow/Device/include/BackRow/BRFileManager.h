/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/BackRow.framework/BackRow
 */

#import "BRSingleton.h"


@interface BRFileManager : BRSingleton {
}
+ (void)setSingleton:(id)singleton;	// 0x3164ea71
+ (id)singleton;	// 0x3164ea65
- (id)attributesOfItemAtPath:(id)path error:(id *)error;	// 0x3164ebd9
- (id)cachePath;	// 0x3164eed9
- (id)contentsOfDirectoryAtPath:(id)path error:(id *)error;	// 0x3164ec0d
- (BOOL)copyItemAtPath:(id)path toPath:(id)path2 error:(id *)error;	// 0x3164eb2d
- (BOOL)createDirectoryAtPath:(id)path attributes:(id)attributes error:(id *)error;	// 0x3164ec79
- (BOOL)fileExistsAtPath:(id)path;	// 0x3164eba5
- (BOOL)fileExistsAtPath:(id)path isDirectory:(BOOL *)directory;	// 0x3164eb6d
- (id)modDateOfFileAtPath:(id)path error:(id *)error;	// 0x3164eaa9
- (id)mostRecentModDateInDirectoryAtPath:(id)path error:(id *)error;	// 0x3164ecbd
- (BOOL)moveItemAtPath:(id)path toPath:(id)path2 error:(id *)error;	// 0x3164eaed
- (void)removeContentsOfDirectoryAtPath:(id)path error:(id *)error;	// 0x3164eded
- (BOOL)removeItemAtPath:(id)path error:(id *)error;	// 0x3164ec41
- (id)videoCachePath;	// 0x3164ea7d
@end

