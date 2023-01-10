//
//  QNTxtResolver.h
//  DNS Lookup server
//
//

#import "QNResolverDelegate.h"
#import <Foundation/Foundation.h>

@interface QNTxtResolver : NSObject <QNResolverDelegate>
- (NSArray *)query:(QNDomain *)domain networkInfo:(QNNetworkInfo *)netInfo error:(NSError *__autoreleasing *)error;

- (instancetype)initWithAddress:(NSString *)address;

- (instancetype)initWithAddress:(NSString *)address timeout:(NSUInteger)time;
@end
