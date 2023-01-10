//
//  DnsRecord.h
//  Doh
//
//

#import "QNRecord.h"
#import "QNDnsRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface QNDnsResponse : QNDnsMessage

@property(nonatomic, assign, readonly)NSInteger timestamp;
@property(nonatomic, assign, readonly)QNRecordSource source;
@property(nonatomic,   copy, readonly)NSString *server;
@property(nonatomic, strong, readonly)QNDnsRequest *request;
@property(nonatomic, strong, readonly)NSData *recordData;


@property(nonatomic, assign, readonly)int aa;

@property(nonatomic, assign, readonly)int rCode;

@property(nonatomic,   copy, readonly)NSArray <QNRecord *> *answerArray;
@property(nonatomic,   copy, readonly)NSArray <QNRecord *> *authorityArray;
@property(nonatomic,   copy, readonly)NSArray <QNRecord *> *additionalArray;

+ (instancetype)dnsResponse:(NSString *)server source:(QNRecordSource)source request:(QNDnsRequest *)request dnsRecordData:(NSData *)recordData error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
