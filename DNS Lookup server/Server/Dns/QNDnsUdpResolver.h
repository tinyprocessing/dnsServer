//
//  QNDnsServer.h
//  Doh
//
//

#import "QNDnsResolver.h"

NS_ASSUME_NONNULL_BEGIN

@interface QNDnsUdpResolver : QNDnsResolver


/// 8.8.8.8
+ (instancetype)resolverWithServerIP:(NSString *)serverIP;


/// @param serverIP :8.8.8.8
/// @param recordType kQNTypeA
/// @param timeout 60
+ (instancetype)resolverWithServerIP:(NSString *)serverIP
                          recordType:(int)recordType
                             timeout:(int)timeout;


+ (instancetype)resolverWithServerIPs:(NSArray <NSString *> *)serverIPs
                           recordType:(int)recordType
                              timeout:(int)timeout;


+ (instancetype)resolverWithServerIPs:(NSArray <NSString *> *)serverIPs
                           recordType:(int)recordType
                                queue:(dispatch_queue_t _Nullable)queue
                              timeout:(int)timeout;

@end

NS_ASSUME_NONNULL_END
