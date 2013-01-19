/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/BackRow.framework/BackRow
 */

#import "BRProvider.h"

@class BRDataStore;
@protocol BRControlFactory;

@interface BRDataStoreProvider : NSObject <BRProvider> {
@private
	id<BRControlFactory> _controlFactory;	// 4 = 0x4
	BRDataStore *_dataStore;	// 8 = 0x8
}
@property(retain) id controlFactory;	// G=0x31621209; S=0x31621695; converted property
@property(readonly, retain) BRDataStore *dataStore;	// G=0x31621219; converted property
+ (id)providerWithDataStore:(id)dataStore;	// 0x31621925
+ (id)providerWithDataStore:(id)dataStore controlFactory:(id)factory;	// 0x316218ed
- (id)initWithDataStore:(id)dataStore;	// 0x31621789
- (id)initWithDataStore:(id)dataStore controlFactory:(id)factory;	// 0x31621751
- (void)_databaseMessagesSuppressed:(id)suppressed;	// 0x31621591
- (void)_databaseObjectWasAdded:(id)added;	// 0x316214ad
- (void)_databaseObjectWasModified:(id)modified;	// 0x31621389
- (void)_databaseObjectWillBeDeleted:(id)_databaseObject;	// 0x316212dd
- (void)_hostAvailabilityChanged:(id)changed;	// 0x31621285
- (void)_updateDataIfNeeded:(id)needed;	// 0x31621229
// converted property getter: - (id)controlFactory;	// 0x31621209
- (id)data;	// 0x316215b1
- (id)dataAtIndex:(long)index;	// 0x31621631
- (long)dataCount;	// 0x31621665
// converted property getter: - (id)dataStore;	// 0x31621219
- (void)dealloc;	// 0x316216cd
- (id)hashForDataAtIndex:(long)index;	// 0x316215ed
// converted property setter: - (void)setControlFactory:(id)factory;	// 0x31621695
@end

