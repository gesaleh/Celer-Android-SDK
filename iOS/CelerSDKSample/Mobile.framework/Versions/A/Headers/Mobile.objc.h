// Objective-C API for talking to github.com/celer-network/goCeler/mobile Go package.
//   gobind -lang=objc github.com/celer-network/goCeler/mobile
//
// File is generated by gobind. Do not edit.

#ifndef __Mobile_H__
#define __Mobile_H__

@import Foundation;
#include "Universe.objc.h"


@class MobileBalance;
@class MobileBooleanCondition;
@class MobileCApp;
@class MobileClient;
@class MobileGroup;
@class MobileGroupClient;
@class MobileGroupResp;
@class MobileRoundResp;
@protocol MobileCAppCallback;
@class MobileCAppCallback;
@protocol MobileGroupCallback;
@class MobileGroupCallback;

@protocol MobileCAppCallback <NSObject>
- (BOOL)onReceiveState:(NSData*)state;
- (void)onStatusChanged:(long)status;
@end

@protocol MobileGroupCallback <NSObject>
- (void)onRecvGroup:(MobileGroupResp*)resp err:(NSString*)err;
@end

/**
 * offchain balance struct
 */
@interface MobileBalance : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)available;
- (void)setAvailable:(NSString*)v;
- (NSString*)pending;
- (void)setPending:(NSString*)v;
- (NSString*)total;
- (void)setTotal:(NSString*)v;
@end

@interface MobileBooleanCondition : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (int64_t)timeout;
- (void)setTimeout:(int64_t)v;
- (NSString*)sessionID;
- (void)setSessionID:(NSString*)v;
- (NSData*)argsForIsFinal;
- (void)setArgsForIsFinal:(NSData*)v;
- (NSData*)argsForQueryResult;
- (void)setArgsForQueryResult:(NSData*)v;
@end

@interface MobileCApp : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)contractBin;
- (void)setContractBin:(NSString*)v;
- (NSString*)contractAbi;
- (void)setContractAbi:(NSString*)v;
- (id<MobileCAppCallback>)callback;
- (void)setCallback:(id<MobileCAppCallback>)v;
@end

@interface MobileClient : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
/**
 * NewClient creates a new Celer Client based on provided config
@param keyStore the keystore json file content
@param pass	passphrase for keystore
@param cfg json format Celer config
@return a Celer client or null if error
@throws Exception
 */
- (instancetype)init:(NSString*)keyStore pass:(NSString*)pass cfg:(NSString*)cfg;
- (BOOL)endCAppSession:(NSString*)sessionid winnerIdx:(long)winnerIdx error:(NSError**)error;
/**
 * Get celer offchain balance
option = 1: return balance based on only local knowledge
option = 2: return balance based on local knowledge + on-chain knowledge
 */
- (MobileBalance*)getBalance:(long)option;
/**
 * HasJoinedCeler Check whether address has also joined Celer and
returns its free balance as a decimal string.  It is useful for
checking the state of the intended receiver.
 */
- (NSString*)hasJoinedCeler:(NSString*)addr error:(NSError**)error;
/**
 * JoinCeler network by opening a channel with cNode, blocks until onchain tx completes
return channel id as string or error msg
 */
- (NSString*)joinCeler:(NSString*)tokenaddr amtWei:(NSString*)amtWei peerAmtWei:(NSString*)peerAmtWei error:(NSError**)error;
/**
 * LeaveCeler network by settling all off-chain balance, blocks until onchain tx completes
 */
- (void)leaveCeler;
/**
 * NewCAppSession creates a new CApp session and return the session identifier as string
 */
- (NSString*)newCAppSession:(MobileCApp*)capp constructor:(NSString*)constructor nonce:(int64_t)nonce error:(NSError**)error;
/**
 * NewOnChainOracle creates a new on-chain oracle that the conditional payment could depend on
 */
- (BOOL)newOnChainOracle:(NSString*)oracleAddr abi:(NSString*)abi error:(NSError**)error;
/**
 * ResolvePaymentByOracle resolves a conditional payment if the condition has been settled by the
corresponding on-chain oracle
 */
- (BOOL)resolvePaymentByOracle:(NSString*)oracleAddr error:(NSError**)error;
- (BOOL)sendCAppState:(NSString*)sessionid dst:(NSString*)dst state:(NSData*)state error:(NSError**)error;
/**
 * SendPay amtWei to dst using Celer off-chain payment
 */
- (BOOL)sendPay:(NSString*)dst amtWei:(NSString*)amtWei error:(NSError**)error;
- (BOOL)sendPayWithConditions:(NSString*)dst amtWei:(NSString*)amtWei cond:(MobileBooleanCondition*)cond error:(NSError**)error;
- (NSString*)switchToOnchain:(NSString*)sessionid error:(NSError**)error;
@end

/**
 * Redefined proto types to comply with go bind interface
 */
@interface MobileGroup : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (NSString*)myId;
- (void)setMyId:(NSString*)v;
- (long)size;
- (void)setSize:(long)v;
- (NSString*)users;
- (void)setUsers:(NSString*)v;
- (NSString*)stake;
- (void)setStake:(NSString*)v;
- (long)code;
- (void)setCode:(long)v;
@end

@interface MobileGroupClient : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
/**
 * NewGroupClient connects to svr
 */
- (instancetype)init:(NSString*)svr ksjson:(NSString*)ksjson pass:(NSString*)pass cb:(id<MobileGroupCallback>)cb;
- (BOOL)createPrivate:(MobileGroup*)gr error:(NSError**)error;
- (BOOL)joinPrivate:(MobileGroup*)gr error:(NSError**)error;
- (BOOL)leave:(MobileGroup*)gr error:(NSError**)error;
- (BOOL)quickMatch:(MobileGroup*)gr error:(NSError**)error;
- (BOOL)rematch:(MobileGroup*)gr error:(NSError**)error;
@end

@interface MobileGroupResp : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (MobileGroup*)g;
- (void)setG:(MobileGroup*)v;
- (NSString*)ownerId;
- (void)setOwnerId:(NSString*)v;
- (MobileRoundResp*)round;
- (void)setRound:(MobileRoundResp*)v;
@end

@interface MobileRoundResp : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (instancetype)init;
- (int64_t)id_;
- (void)setID:(int64_t)v;
- (long)firstMoverIdx;
- (void)setFirstMoverIdx:(long)v;
@end

/**
 * NewClient creates a new Celer Client based on provided config
@param keyStore the keystore json file content
@param pass	passphrase for keystore
@param cfg json format Celer config
@return a Celer client or null if error
@throws Exception
 */
FOUNDATION_EXPORT MobileClient* MobileNewClient(NSString* keyStore, NSString* pass, NSString* cfg, NSError** error);

/**
 * NewGroupClient connects to svr
 */
FOUNDATION_EXPORT MobileGroupClient* MobileNewGroupClient(NSString* svr, NSString* ksjson, NSString* pass, id<MobileGroupCallback> cb, NSError** error);

FOUNDATION_EXPORT void MobileOnLog(long num);

@class MobileCAppCallback;

@class MobileGroupCallback;

@interface MobileCAppCallback : NSObject <goSeqRefInterface, MobileCAppCallback> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (BOOL)onReceiveState:(NSData*)state;
- (void)onStatusChanged:(long)status;
@end

@interface MobileGroupCallback : NSObject <goSeqRefInterface, MobileGroupCallback> {
}
@property(strong, readonly) id _ref;

- (instancetype)initWithRef:(id)ref;
- (void)onRecvGroup:(MobileGroupResp*)resp err:(NSString*)err;
@end

#endif