//
//  QNRecord.h
//  DNS Lookup server
//
//

#import <Foundation/Foundation.h>

/**
 *    A
 */
extern const int kQNTypeA;

/**
 *    AAAA
 */
extern const int kQNTypeAAAA;

/**
 *  Cname
 */
extern const int kQNTypeCname;

/**
 *  TXT
 */
extern const int kQNTypeTXT;

/**
 *  TTL
 */
extern const int kQNRecordForeverTTL;

typedef NS_ENUM(NSUInteger, QNRecordSource) {
    QNRecordSourceUnknown,
    QNRecordSourceCustom,
    QNRecordSourceDnspodEnterprise,
    QNRecordSourceSystem,
    QNRecordSourceUdp,
    QNRecordSourceDoh,
};


@interface QNRecord : NSObject

@property (nonatomic,   copy, readonly) NSString *value;
@property (nonatomic,   copy, readonly) NSString *server;
@property (nonatomic, readonly) int ttl;
@property (nonatomic, readonly) int type;
@property (nonatomic, readonly) long long timeStamp;
@property (nonatomic, readonly) QNRecordSource source;

- (instancetype)init:(NSString *)value
                 ttl:(int)ttl
                type:(int)type
              source:(QNRecordSource)source;

- (instancetype)init:(NSString *)value
                 ttl:(int)ttl
                type:(int)type
           timeStamp:(long long)timeStamp
              server:(NSString *)server
              source:(QNRecordSource)source;

- (BOOL)expired:(long long)time;

@end
