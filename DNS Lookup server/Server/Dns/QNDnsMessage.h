//
//  QNDnsMessage.h
//  Doh
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QNDnsMessage : NSObject

@property(nonatomic, assign, readonly)int messageId;

@property(nonatomic, assign, readonly)int opCode;

@property(nonatomic, assign, readonly)int rd;

@property(nonatomic, assign, readonly)int ra;

@end

NS_ASSUME_NONNULL_END
