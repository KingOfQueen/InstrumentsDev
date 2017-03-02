//
//  XRBacktraceRepository.h
//  MacDemoNew
//
//  Created by yangfl on 2016/12/27.
//  Copyright © 2016年 szzc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
@interface XRBacktraceRepository : NSObject

@end
 */


/*
@protocol XROutlineDetailViewUIDProvider
- (id <NSObject><NSCoding>)outlineView:(XROutlineDetailView *)arg1 uidForItem:(id)arg2;
@end
*/

/*
@interface XRBacktraceRepository : NSObject <NSCoding, NSOutlineViewDataSource, NSOutlineViewDelegate, XROutlineDetailViewUIDProvider>
{
    int _pid;
    NSString *_processName;
    PFTPersistentSymbols *_persistentSymbols;
    NSMutableArray *_allSamples;
    NSMutableDictionary *_samplesForCategory;
    NSString *_defaultCategoryName;
    int _symbolicationTiming;
    NSMutableDictionary *_activeTrimming;
    NSMutableDictionary *_activeFilters;
    NSString *_activeCategory;
    NSMutableArray *_activeSamples;
    PFTCallTreeNode *_currentTreeRoot;
    NSPredicate *_categoryPredicate;
    NSMutableArray *_focusCategories;
    id _focusedNode;
    NSMutableDictionary *_focusInfo;
    NSMutableDictionary *_focusedNodeDataCountForFocusCategory;
    NSMutableDictionary *_focusedNodeDataForFocusCategory;
    id <XRCallTreeDataSource> _dataSource;
    NSObject<OS_dispatch_queue> *_symbolicationQueue;
    NSMutableDictionary *_cachedTreesForCategory;
    struct __CFDictionary *_cachedSortedTreeChildren;
    struct __CFDictionary *_cachedInterestingSymbolInBacktrace;
    struct __CFDictionary *_cachedFullBacktraceStrings;
    BOOL _setupAttempted;
    XRDevice *_associatedDevice;
    struct __CFData *_freezeDriedSignature;
    struct __CFData *_freezeDriedKernelSignature;
    id _treeDataTrackingQuery;
    CDUnknownBlockType _categoryComparator;
    CDUnknownBlockType _summaryCategoryComparator;
    NSMutableDictionary *_outlineViewColumnSortBlocks;
    struct _opaque_pthread_mutex_t _callTreeActionLock;
    XRBacktraceRepository *_mergeRepository;
    XRBacktraceRepository *_settingOverride;
    int _mergeFactor;
    BOOL _needsRecreate;
    BOOL _viewSettingsInitialized;
    struct XRTimeRange _activeTimeRange;
    NSString *_sortID;
    unsigned long long _sortIndex;
    NSEvent *_currentEvent;
    NSMutableSet *_selectedItems;
    BOOL _sortAscending;
    unsigned long long _weightCount;
    XRTrace *_trace;
    long long _runNumber;
    BOOL _firstWeightIsSpecial;
    BOOL _trimMissingSymbols;
    BOOL _showObjCOnly;
}

+ (long long)indexOfTimestamp:(unsigned long long)arg1 inSampleArray:(id)arg2 closestBefore:(BOOL)arg3;
+ (void)initialize;
@property(nonatomic) BOOL showObjCOnly; // @synthesize showObjCOnly=_showObjCOnly;
@property(nonatomic) BOOL trimMissingSymbols; // @synthesize trimMissingSymbols=_trimMissingSymbols;
@property(nonatomic) BOOL firstWeightIsSpecial; // @synthesize firstWeightIsSpecial=_firstWeightIsSpecial;
@property(readonly, nonatomic) unsigned long long weightCount; // @synthesize weightCount=_weightCount;
@property(copy, nonatomic) NSString *processName; // @synthesize processName=_processName;
- (void).cxx_destruct;
- (id)filterContext;
- (SEL)filterSelector;
- (void)setFilterSelector:(SEL)arg1 context:(void *)arg2;
- (id)outlineView:(id)arg1 uidForItem:(id)arg2;
- (BOOL)outlineView:(id)arg1 shouldExpandItem:(id)arg2;
- (id)outlineView:(id)arg1 toolTipForCell:(id)arg2 rect:(struct CGRect *)arg3 tableColumn:(id)arg4 item:(id)arg5 mouseLocation:(struct CGPoint)arg6;
- (void)outlineView:(id)arg1 willDisplayCell:(id)arg2 forTableColumn:(id)arg3 item:(id)arg4;
- (BOOL)outlineView:(id)arg1 shouldShowCellExpansionForTableColumn:(id)arg2 item:(id)arg3;
- (BOOL)shouldDisplayActionInOutlineView:(id)arg1 forItem:(id)arg2;
- (void)outlineView:(id)arg1 didClickTableColumn:(id)arg2;
- (id)_treeNode:(id)arg1 valueForIdentifier:(id)arg2 andIndex:(unsigned long long)arg3;
- (id)outlineView:(id)arg1 objectValueForTableColumn:(id)arg2 byItem:(id)arg3;
- (long long)outlineView:(id)arg1 numberOfChildrenOfItem:(id)arg2;
- (BOOL)outlineView:(id)arg1 isItemExpandable:(id)arg2;
- (id)outlineView:(id)arg1 child:(long long)arg2 ofItem:(id)arg3;
- (void)sortOutlineColumnName:(id)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)_setSortIdentifier:(id)arg1 sortIndex:(unsigned long long)arg2 ascending:(BOOL)arg3 outlineView:(id)arg4;
- (void)_setSortIdentifier:(id)arg1 ascending:(BOOL)arg2 outlineView:(id)arg3;
- (id)highlightColumnInOutlineView:(id)arg1;
- (void)setSortIdentifier:(id)arg1 sortIndex:(unsigned long long)arg2 ascending:(BOOL)arg3;
- (void)setSortIdentifier:(id)arg1 ascending:(BOOL)arg2;
- (void)_addNodesToTopFunctionsTreeRoot:(id)arg1 firstLevelLookup:(id)arg2;
- (void)refreshTreeRoot;
- (id)_newTreeRoot;
- (id)_treeForCat:(id)arg1;
- (void)setContainedCategoryTokens:(id)arg1 matchesAny:(BOOL)arg2;
- (void)_applyDataMiningToCallTreeRoot:(id)arg1;
- (BOOL)_pruneLibraryTokensOr;
- (id)_pruneLibraryTokens;
- (BOOL)_pruneSymbolTokensOr;
- (id)_pruneSymbolTokens;
- (id)concatenatedSymbolNamesForBacktrace:(id)arg1;
- (id)interestingSymbolInBacktrace:(id)arg1;
- (BOOL)shouldIgnoreSymbol:(id)arg1;
- (id)backtraceRepository;
- (id)rootBinding;
- (id)rootNode;
- (void)pruneByRequiringLibraryNameTokens:(id)arg1 requireAny:(BOOL)arg2;
- (void)pruneByRequiringSymbolNameTokens:(id)arg1 requireAny:(BOOL)arg2;
- (id)boundaryLibraries;
- (id)flattenedLibraries;
- (id)prunedSymbols;
- (id)flattenedSymbols;
- (void)flattenLibraryOfSymbolToBoundaries:(id)arg1;
- (void)flattenLibraryOfSymbol:(id)arg1;
- (void)restoreLibraryOfSymbol:(id)arg1;
- (void)pruneSymbol:(id)arg1;
- (void)flattenSymbol:(id)arg1;
- (void)downloadDSYM:(id)arg1;
- (void)symbolicateAddress:(id)arg1;
- (void)locateAndSymbolicateAddress:(id)arg1;
- (void)restoreSymbol:(id)arg1;
- (void)_modifyLibraryTrimming:(id)arg1 option:(int)arg2;
- (void)_modifySymbolTrimming:(id)arg1 option:(int)arg2;
@property(nonatomic) unsigned int maximumTreeBranchCount;
@property(nonatomic) unsigned int minimumTreeBranchCount;
- (BOOL)treeBranchCountFiltering;
- (long long)maximumTreeBranchWeight;
- (void)setMaximumTreeBranchWeight:(double)arg1;
- (BOOL)treeBranchWeightFiltering;
- (long long)minimumTreeBranchWeight;
- (void)setMinimumTreeBranchWeight:(double)arg1;
@property(nonatomic) BOOL topFunctions;
@property(nonatomic) BOOL showProcessesByCategory;
@property(nonatomic) BOOL showCategoryAsLeaf;
@property(nonatomic) BOOL showAllAsCategory;
@property(nonatomic) BOOL inverted;
@property(nonatomic) BOOL separateByCategory;
@property(nonatomic) BOOL separateByThread;
@property(nonatomic) BOOL flattenRecursion;
@property(nonatomic) BOOL trimSystemLibraries;
- (void)clearAllTrimmingRules;
- (void)mergeTreesWithRepository:(id)arg1 factor:(int)arg2;
- (void)_setOverrideRepository:(id)arg1;
- (struct XRTimeRange)timeRangeFilter;
- (void)setTimeRangeFilter:(struct XRTimeRange)arg1;
- (void)clearAllFilters;
- (id)threadNameForThread:(unsigned long long)arg1 pid:(int)arg2;
- (id)threadNameForThreadId:(unsigned long long)arg1 backtrace:(id)arg2;
- (unsigned long long)activeThread;
- (void)setActiveThread:(unsigned long long)arg1;
- (void)setFocusNode:(id)arg1;
- (id)_samplesInSubtreeOfTreeNode:(id)arg1;
- (id)activeCategory;
- (void)setActiveCategory:(id)arg1;
@property(nonatomic) BOOL viewSettingsInitialized;
- (void)_jumpToXcodeForSymbol:(id)arg1;
- (void)focusLibraryCallees:(id)arg1;
- (void)focusLibraryCallers:(id)arg1;
- (void)focusSymbolCallees:(id)arg1;
- (void)focusSymbolCallers:(id)arg1;
- (void)focusSubtree:(id)arg1;
- (void)_setFocusObject:(id)arg1 forKey:(id)arg2 andNotifyUpdate:(BOOL)arg3;
- (void)_resetFocus;
- (id)dataMiningMenuForItem:(id)arg1 allowRevealSymbol:(BOOL)arg2;
- (id)samplesByLineSpecificSymbolForTreeNode:(id)arg1;
- (void)_setTrackedTreeData:(id)arg1;
- (id)nameForPid:(int)arg1;
- (id)symbolStringsForBacktrace:(id)arg1 reverseOrder:(BOOL)arg2;
- (id)symbolsForBacktrace:(id)arg1 reverseOrder:(BOOL)arg2;
- (id)hottestSymbolInBacktrace:(id)arg1;
- (id)libraryForAddress:(unsigned long long)arg1;
- (id)symbolForPC:(unsigned long long)arg1;
- (id)samplesForCategory:(id)arg1;
- (void)applyFocusInformation:(id)arg1;
- (void)_applyFocusInformation:(id)arg1 refresh:(BOOL)arg2;
- (void)_applyFiltersAndTrimming:(id)arg1;
- (void)_focusUsingFocusInfo:(id)arg1;
- (id)focusInformation;
- (id)focusTitle;
- (id)iconForFocusInformation:(id)arg1;
- (void)setNeedsForceReloadData:(BOOL)arg1;
- (void)setCallTreeDataSource:(id)arg1;
- (void)prepareForResymbolication;
- (void)_clearCaches;
- (void)_wipeTree;
- (void)clearCategory:(id)arg1;
- (void)setComparatorForSummaryCategoryNames:(CDUnknownBlockType)arg1;
- (void)setComparatorForCategoryNames:(CDUnknownBlockType)arg1;
- (void)setNameForDefaultCategory:(id)arg1;
- (void)learnSymbolicInformationForBacktrace:(id)arg1;
- (void)_learnSymbolicInformationForBacktrace:(id)arg1 queue:(id)arg2;
- (void)storeSample:(id)arg1 forCategory:(id)arg2 excludeFromDefaultCategory:(BOOL)arg3 needsSymbolication:(BOOL)arg4;
- (void)storeBacktrace:(id)arg1 forCategory:(id)arg2 excludeFromDefaultCategory:(BOOL)arg3 weight:(double)arg4 timestamp:(unsigned long long)arg5 eventType:(unsigned int)arg6 thread:(unsigned int)arg7 extendedData:(id)arg8 needsSymbolication:(BOOL)arg9;
- (void)setSymbolicationTiming:(int)arg1;
- (struct __CFData *)kernelSignature;
- (struct __CFData *)signatureForPid:(int)arg1;
- (id)allRepositories;
- (id)repositoryForPid:(int)arg1;
- (int)pid;
- (id)symbolProvider;
- (BOOL)_setupSymbolProviderWithPid:(int)arg1 forDevice:(id)arg2;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)dealloc;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)didResymbolicate:(id)arg1;
- (void)willResymbolicate:(id)arg1;
- (id)initWithDevice:(id)arg1 trace:(id)arg2 runNumber:(long long)arg3 pid:(int)arg4 signature:(struct __CFData *)arg5 kernelSignature:(struct __CFData *)arg6 weightCount:(unsigned long long)arg7;
- (id)initWithDevice:(id)arg1 pid:(int)arg2 signature:(struct __CFData *)arg3 kernelSignature:(struct __CFData *)arg4;
- (id)initWithDevice:(id)arg1 pid:(int)arg2 weightCount:(unsigned long long)arg3;
- (id)initWithDevice:(id)arg1 pid:(int)arg2;
- (id)initWithDevice:(id)arg1 weightCount:(unsigned long long)arg2;
- (id)initWithDevice:(id)arg1;
- (id)init;
- (void)_commonRepositoryInit;
- (CDUnknownBlockType)_createSymbolTestBlock;
- (id)_trackedTreeData;
- (int)_requiredFocusCount;
- (id)_leafNameForSample:(id)arg1;
- (BOOL)_setupWithSymbolProvider:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
*/
