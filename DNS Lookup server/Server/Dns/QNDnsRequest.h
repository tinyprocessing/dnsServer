//
//  DnsQuestion.h
//  Doh
//
//

#import "QNDnsDefine.h"
#import "QNDnsMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface QNDnsRequest : QNDnsMessage

@property(nonatomic, assign, readonly)int recordType;
@property(nonatomic,   copy, readonly)NSString *host;

+ (instancetype)request:(int)messageId
             recordType:(int)recordType
                   host:(NSString *)host;

+ (instancetype)request:(int)messageId
                 opCode:(QNDnsOpCode)opCode
                     rd:(int)rd
             recordType:(int)recordType
                   host:(NSString *)host;

- (NSData *)toDnsQuestionData:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
