//
//  EventsDataSource.h
//  IRCCloud
//
//  Created by Sam Steele on 2/27/13.
//  Copyright (c) 2013 IRCCloud, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IRCCloudJSONObject.h"

@interface Event : NSObject {
    int _cid;
    int _bid;
    NSTimeInterval _eid;
    NSString *_timestamp;
    NSString *_type;
    NSString *_msg;
    NSString *_hostmask;
    NSString *_from;
    NSString *_fromMode;
    NSString *_nick;
    NSString *_oldNick;
    NSString *_server;
    NSString *_diff;
    NSString *_formattedMsg;
    NSAttributedString *_formatted;
    BOOL _isHighlight;
    BOOL _isSelf;
    BOOL _toChan;
    UIColor *_color;
    UIColor *_bgColor;
    NSDictionary *_ops;
    NSTimeInterval _groupEid;
    int _rowType;
    NSString *_groupMsg;
    BOOL _linkify;
    NSString *_targetMode;
    int _reqid;
    BOOL _pending;
}
@property int cid, bid, rowType, reqId;
@property NSTimeInterval eid, groupEid;
@property NSString *timestamp, *type, *msg, *hostmask, *from, *fromMode, *nick, *oldNick, *server, *diff, *groupMsg, *targetMode, *formattedMsg;
@property BOOL isHighlight, isSelf, toChan, linkify, pending;
@property NSDictionary *ops;
@property UIColor *color, *bgColor;
@property NSAttributedString *formatted;
-(NSComparisonResult)compare:(Event *)aEvent;
-(BOOL)isImportant:(NSString *)bufferType;
@end

@interface EventsDataSource : NSObject {
    NSMutableDictionary *_events;
    NSTimeInterval _highestEid;
}
@property NSTimeInterval highestEid;
+(EventsDataSource *)sharedInstance;
-(void)clear;
-(void)addEvent:(Event *)event;
-(Event *)addJSONObject:(IRCCloudJSONObject *)object;
-(Event *)event:(NSTimeInterval)eid buffer:(int)bid;
-(void)removeEvent:(NSTimeInterval)eid buffer:(int)bid;
-(void)removeEventsForBuffer:(int)bid;
-(NSArray *)eventsForBuffer:(int)bid;
-(void)removeEventsBefore:(NSTimeInterval)min_eid buffer:(int)bid;
-(int)unreadCountForBuffer:(int)bid lastSeenEid:(NSTimeInterval)lastSeenEid type:(NSString *)type;
-(int)highlightCountForBuffer:(int)bid lastSeenEid:(NSTimeInterval)lastSeenEid type:(NSString *)type;
@end