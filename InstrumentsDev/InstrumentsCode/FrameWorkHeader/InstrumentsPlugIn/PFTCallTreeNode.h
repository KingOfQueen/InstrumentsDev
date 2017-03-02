//
//  PFTCallTreeNode.h
//  MacDemoNew
//
//  Created by yangfl on 2017/1/8.
//  Copyright © 2017年 szzc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
@interface PFTCallTreeNode : NSObject

@end
*/

/*
@protocol CommonSymbol <NSCoding, NSObject>
- (NSString *)libraryPath;
- (NSString *)libraryName;
- (NSString *)symbolName;
- (int)pid;
- (unsigned long long)lineNumber;
- (NSString *)sourcePath;
- (unsigned long long)address;

@optional
- (PFTSymbolData *)resolvedSymbol;
@end
*/

/*
@protocol XRUIStackFrame <NSCoding, NSObject>
- (long long)lineNumberForDisplay;
- (NSString *)pathForDisplay;
- (NSString *)symbolNameForUse;
- (NSString *)symbolNameForDisplay;
- (NSString *)libraryForDisplay;

@optional
- (BOOL)getWeight:(double *)arg1 at:(unsigned long long)arg2;
@end
*/

/*
@protocol CommonTimeSample <NSCoding, NSObject>
- (id)extendedData;
- (id <CommonRawStack>)backtrace;
- (double)weight;
- (int)quantity;
- (unsigned long long)thread;
- (unsigned int)eventType;
- (unsigned long long)timestamp;

@optional
- (double)weightAtIndex:(unsigned int)arg1;
- (unsigned int)cpuIndex;
@end
*/

/*
@interface PFTCallTreeNode : NSObject <CommonSymbol, XRUIStackFrame>
{
    void *_chunk;
    NSString *name;
    id data;
    unsigned long long parentalAddress;
    unsigned int terminals;
    int count;
    PFTCallTreeNode *representedNode;
    PFTCallTreeNode *parent;
    PFTCallTreeNode *root;
    PFTCallTreeNode *firstKids[2];
    struct __CFDictionary *childrenDict;
    int numberOfChildren;
    int pid;
    unsigned int _nodeFlags;
    id _cachedChildData;
    PFTCallTreeNode *_cachedChild;
    struct __CFDictionary *_terminalSamplesByKeyAddress;
    BOOL _childRetainsParent;
    unsigned long long _weightCount;
    struct {
        double selfWeight;
        double weight;
    } weights[1];
}

+ (id)newNodeWithWeightCount:(unsigned long long)arg1 name:(id)arg2;
+ (id)newNodeWithWeightCount:(unsigned long long)arg1;
+ (id)allocWithWeightCount:(unsigned long long)arg1;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (long long)lineNumberForDisplay;
- (id)pathForDisplay;
- (id)symbolNameForUse;
- (BOOL)getWeight:(double *)arg1 at:(unsigned long long)arg2;
- (id)symbolNameForDisplay;
- (id)libraryForDisplay;
- (id)libraryPath;
- (id)libraryName;
- (unsigned long long)lineNumber;
- (id)sourcePath;
- (unsigned long long)address;
- (BOOL)recursivelyTrimLibraries:(id)arg1 keepBoundaries:(BOOL)arg2;
- (BOOL)recursivelyTrimSymbols:(id)arg1 prune:(BOOL)arg2;
- (BOOL)_recursivePruneWithBlock:(CDUnknownBlockType)arg1;
- (void)recursivelyPruneLeavingLibraryNames:(id)arg1 requireAny:(BOOL)arg2;
- (void)recursivelyPruneLeavingSymbolNames:(id)arg1 requireAny:(BOOL)arg2;
- (void)recursivePruneByWeightWithMin:(long long)arg1 max:(long long)arg2;
- (void)recursivePruneByCountWithMin:(unsigned int)arg1 max:(unsigned int)arg2;
- (void)mergeWithNode:(id)arg1 factor:(int)arg2;
- (void)flattenAllRecursion;
- (void)pruneChild:(id)arg1;
- (void)flattenChild:(id)arg1;
- (BOOL)recursiveFlattenWithDataSelector:(SEL)arg1 filterNonZero:(BOOL)arg2;
- (BOOL)recursiveFlattenWithPredicate:(id)arg1;
- (id)_heaviestInvolvingNodeWithStyle:(int)arg1;
- (id)heaviestInvolvingNodeAsCounts;
- (id)heaviestInvolvingNodeAsWeights;
- (id)heaviestInvolvingNodeAsBytes;
- (id)heaviestInvolvingNode;
- (double)selfCountPercent;
- (double)totalCountPercent;
- (double)parentCountPercent;
- (double)selfWeightPercent:(unsigned long long)arg1;
- (double)totalWeightPercent:(unsigned long long)arg1;
- (double)parentWeightPercent:(unsigned long long)arg1;
- (id)symbolData;
- (id)_symbolData;
- (id)data;
- (id)symbol;
- (void)setName:(id)arg1;
- (id)symbolName;
- (void)setShowAsCounts:(id)arg1;
- (void)setShowAsBytes:(id)arg1;
- (id)totalBytes;
- (id)selfBytes;
- (int)terminals;
- (int)count;
- (double)selfWeight:(unsigned long long)arg1;
- (double)weight:(unsigned long long)arg1;
- (unsigned long long)weightCount;
- (int)pid;
- (int)numberChildren;
- (id)children;
- (id)uidSet;
- (id)childWithSymbolName:(id)arg1;
- (id)childWithUid:(id)arg1;
- (id)symbolNamePath;
- (id)uidPath;
- (id)uid;
- (id)parent;
- (id)root;
- (id)_gatherSamples;
- (void)_recursiveGatherSamples:(id)arg1;
- (id)_assembleLineSpecificData;
- (void)_recursiveAssembleLineSpecificData:(id)arg1 baseSymbolData:(id)arg2;
- (void)setRoot:(id)arg1;
- (void)adopt:(id)arg1 merge:(BOOL)arg2 compare:(BOOL)arg3;
- (unsigned int)_thread;
- (void)fixupCounts;
- (id)getConcreteParent;
- (void)setDoNotRecalcWeightFlag;
- (void)setTopFunctionsFlag;
- (void)setIsTopOfStackFlag;
- (void)setPrivateDataFlag;
- (void)setIsInvertedFlag;
- (void)addTerminals:(int)arg1;
- (void)addSelfWeight:(double)arg1 forIndex:(unsigned long long)arg2;
- (void)addWeight:(double)arg1 forIndex:(unsigned long long)arg2;
- (long long)addSamples:(id)arg1 range:(struct _NSRange)arg2 leafName:(id)arg3 controller:(id)arg4 dataMining:(CDUnknownBlockType)arg5 firstLevelLookup:(id)arg6;
- (long long)addSamples:(id)arg1 range:(struct _NSRange)arg2 leafName:(id)arg3 controller:(id)arg4 dataMining:(CDUnknownBlockType)arg5;
- (id)addNewChildWithData:(id)arg1;
- (id)childThatMatchesNode:(id)arg1;
@property(readonly, copy) NSString *description;
- (id)representedObject;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)copyWithDataForAddress:(unsigned long long)arg1;
- (void)_assignParent:(id)arg1 retain:(BOOL)arg2;
- (id)initWithName:(id)arg1;
- (id)init;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
 */
