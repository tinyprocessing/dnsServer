//
//  QNResolver.h
//  DNS Lookup server
//
//

#import "QNResolverDelegate.h"
#import <Foundation/Foundation.h>

@interface QNResolver : NSObject <QNResolverDelegate>
- (NSArray *)query:(QNDomain *)domain networkInfo:(QNNetworkInfo *)netInfo error:(NSError *__autoreleasing *)error;

// @deprecated typo
- (instancetype)initWithAddres:(NSString *)address DEPRECATED_ATTRIBUTE;

- (instancetype)initWithAddress:(NSString *)address;

- (instancetype)initWithAddress:(NSString *)address
                        timeout:(NSUInteger)time;

+ (instancetype)systemResolver;
+ (NSString *)systemDnsServer;
@end
