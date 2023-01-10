//
//  QNDnsResolver.h
//  DNS Lookup server
//
//

#import "QNDnsDefine.h"
#import "QNRecord.h"
#import "QNResolverDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class QNDnsResponse;

@interface QNDnsResolver : NSObject <QNResolverDelegate>

@property(nonatomic, assign, readonly)int recordType;
@property(nonatomic, assign, readonly)int timeout;
@property(nonatomic,   copy, readonly)NSArray *servers;


- (void)request:(NSString *)server
           host:(NSString *)host 
     recordType:(int)recordType
       complete:(void(^)(QNDnsResponse *response, NSError *error))complete;

@end

NS_ASSUME_NONNULL_END
