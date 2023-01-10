//
//  QNLruCache.h
//  DNS Lookup server
//
//

#import <Foundation/Foundation.h>

@interface QNLruCache : NSObject

- (instancetype)init:(NSUInteger)limit;

- (void)removeAllObjects;

- (void)removeObjectForKey:(NSString *)key;

- (id)objectForKey:(NSString *)key;

- (void)setObject:(id)obj forKey:(NSString *)key;

@end
