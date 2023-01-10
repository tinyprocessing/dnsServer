//
//  Doh.h
//  Doh
//
//

#import "QNDnsResolver.h"
#import "QNDnsDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface QNDohResolver : QNDnsResolver

/// https://dns.google/dns-query
+ (instancetype)resolverWithServer:(NSString *)server;

+ (instancetype)resolverWithServer:(NSString *)server
                        recordType:(int)recordType
                           timeout:(int)timeout;

+ (instancetype)resolverWithServers:(NSArray <NSString *> *)servers
                         recordType:(int)recordType
                            timeout:(int)timeout;

@end

NS_ASSUME_NONNULL_END
