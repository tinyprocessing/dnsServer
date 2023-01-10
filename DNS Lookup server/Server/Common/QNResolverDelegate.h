//
//  QNResolverDelegate.h
//  DNS Lookup server
//
//

#import "QNDnsError.h"

#define QN_DNS_DEFAULT_TIMEOUT 20 //seconds

@class QNDomain;
@class QNNetworkInfo;
@protocol QNResolverDelegate <NSObject>

- (NSArray *)query:(QNDomain *)domain networkInfo:(QNNetworkInfo *)netInfo error:(NSError **)error;

@end
