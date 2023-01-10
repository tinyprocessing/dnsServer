//
//  QNDomain.h
//  DNS Lookup server
//
//

#import <Foundation/Foundation.h>

@interface QNDomain : NSObject
@property (nonatomic, strong, readonly) NSString *domain;


@property (nonatomic, readonly) BOOL hasCname;

@property (nonatomic, readonly) int maxTtl;

@property (nonatomic, readonly) BOOL hostsFirst;

- (instancetype)init:(NSString *)domain;

- (instancetype)init:(NSString *)domain hostsFirst:(BOOL)hostsFirst hasCname:(BOOL)hasCname;

- (instancetype)init:(NSString *)domain hostsFirst:(BOOL)hostsFirst hasCname:(BOOL)hasCname maxTtl:(int)maxTtl;

@end
