//
//  QNHosts.h
//  DNS Lookup server
//
//

#import "QNRecord.h"
#import "QNResolverDelegate.h"
#import <Foundation/Foundation.h>

@interface QNHosts : NSObject

- (NSArray <QNRecord *> *)query:(QNDomain *)domain networkInfo:(QNNetworkInfo *)netInfo;

- (void)put:(NSString *)domain record:(QNRecord *)record;
- (void)put:(NSString *)domain record:(QNRecord *)record provider:(int)provider;

@end
