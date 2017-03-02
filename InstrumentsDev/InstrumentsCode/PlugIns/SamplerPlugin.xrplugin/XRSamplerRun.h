//
//  XRSamplerRun.h
//  MacDemoNew
//
//  Created by yangfl on 2016/12/28.
//  Copyright © 2016年 szzc. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
@interface XRSamplerRun : NSObject

@end
*/

/*
@interface XRSamplerRun : XRRun <SymbolAwareRun, XRSourceQuery, XRCallTreeDataSource>
{
    XRStorageManager *_storageManager;
    XRBacktraceRepository *_backtraceRepository;
    int _numberProcessors;
    int _options;
    int _samplerMode;
    unsigned long long _sampleRateMicroseconds;
    NSString *_pmiEventMnemonic;
    NSString *_pmiCounterName;
    unsigned long long _pmiEventThreshold;
    int _target;
    NSMutableDictionary *_threadsByTid;
    unsigned int _displayedEvent;
    unsigned int _maxStackDepth;
    NSMutableArray *_spinSessions;
    XRSamplerDataReceiver *_dataReceiver;
    unsigned int _nextThreadDiscoveryIndex;
    NSDate *_startDate;
}

+ (void)initialize;
@property(readonly) unsigned int maxStackDepth; // @synthesize maxStackDepth=_maxStackDepth;
@property(nonatomic) unsigned int displayedEvent; // @synthesize displayedEvent=_displayedEvent;
@property(readonly) XRStorageManager *storageManager; // @synthesize storageManager=_storageManager;
@property(readonly) int allowedTarget; // @synthesize allowedTarget=_target;
@property(readonly) int samplerOptions; // @synthesize samplerOptions=_options;
@property(readonly) int numberOfProcessors; // @synthesize numberOfProcessors=_numberProcessors;
@property(nonatomic) unsigned long long pmiEventThreshold; // @synthesize pmiEventThreshold=_pmiEventThreshold;
@property(retain, nonatomic) NSString *pmiCounterName; // @synthesize pmiCounterName=_pmiCounterName;
@property(retain, nonatomic) NSString *pmiEventMnemonic; // @synthesize pmiEventMnemonic=_pmiEventMnemonic;
@property(nonatomic) int samplerMode; // @synthesize samplerMode=_samplerMode;
@property(nonatomic) unsigned long long sampleRate; // @synthesize sampleRate=_sampleRateMicroseconds;
- (void).cxx_destruct;
- (id)provideCursorForNavigator:(id)arg1;
- (BOOL)canProvideCursorForNavigator:(id)arg1;
- (void)voteForEpoch:(id)arg1;
- (id)operation:(id)arg1 commentsForSymbol:(id)arg2 forProcess:(int)arg3 inSourceManager:(id)arg4 callTreeInformation:(id)arg5;
- (id)operation:(id)arg1 commentsForSymbol:(id)arg2 inSourceManager:(id)arg3 callTreeInformation:(id)arg4;
- (BOOL)loadCoreProfileSampleDataFromFileWithPath:(id)arg1;
- (BOOL)loadDTPerformanceSessionDataFromPaths:(id)arg1 error:(id *)arg2;
- (BOOL)loadSampleDataFromPaths:(id)arg1 withMode:(int)arg2 error:(id *)arg3;
- (id)additionalSupportedBrushNamesForStrategy:(id)arg1;
- (id)backtracesForCategory:(id)arg1 timeRange:(struct XRTimeRange)arg2 savedIndex:(unsigned long long *)arg3;
- (id)processCategoriesForPid:(int)arg1;
- (id)backtraceRepository;
- (void)resymbolicationDidComplete;
- (void)enumerateEventsInRange:(struct XRTimeRange)arg1 withBlock:(CDUnknownBlockType)arg2;
- (id)eventForIdentifier:(unsigned int)arg1;
- (unsigned int)latestEventIdentifierBeforeTimestamp:(unsigned long long)arg1;
- (unsigned int)closestEventIdentifierAfterTimestamp:(unsigned long long)arg1;
- (id)processNameForPid:(int)arg1;
@property(readonly) NSArray *allThreads;
- (id)threadForEvent:(id)arg1;
@property(readonly) unsigned long long lastTimestamp;
- (unsigned long long)_currentTimestamp;
- (void)discoverNewThreads;
- (void)pauseRecording:(BOOL)arg1;
- (BOOL)stopRecordingWithPid:(int)arg1;
- (BOOL)startRecordingWithPid:(int)arg1;
- (void)suspendDataCollection:(double)arg1;
- (void)setStart:(double)arg1;
- (void)_prepareForDevice:(id)arg1 options:(int)arg2 pid:(int)arg3 receiverClass:(Class)arg4;
- (void)prepareForDevice:(id)arg1 options:(int)arg2 pid:(int)arg3;
- (unsigned long long)weightCount;
- (BOOL)recordUserStacks;
- (BOOL)recordKernelStacks;
- (id)initWithCoder:(id)arg1;
- (id)_storagePathForVersion:(long long)arg1;
- (unsigned long long)numberOfGraphs;
- (void)encodeWithCoder:(id)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
 
*/
