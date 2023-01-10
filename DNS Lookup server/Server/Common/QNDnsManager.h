//
//  QNDnsManager.h
//  DNS Lookup server
//
//

#import "QNRecord.h"

@class QNNetworkInfo;
@class QNDomain;


typedef NSArray<NSString *> * (^QNGetAddrInfoCallback)(NSString *host);


typedef void (^QNIpStatusCallback)(NSString *ip, int code, int ms);

@protocol QNRecordSorter <NSObject>


- (NSArray<QNRecord *> *)sort:(NSArray<QNRecord *> *)ips;
@end


@interface QNDnsManager : NSObject


@property(nonatomic,  copy)void(^queryErrorHandler)(NSError *error, NSString *host);


- (NSArray <QNRecord *> *)queryRecords:(NSString *)domain;


- (NSArray <QNRecord *> *)queryRecordsWithDomain:(QNDomain *)domain;


- (void)onNetworkChange:(QNNetworkInfo *)netInfo;


- (instancetype)init:(NSArray *)resolvers networkInfo:(QNNetworkInfo *)netInfo;


- (instancetype)init:(NSArray *)resolvers networkInfo:(QNNetworkInfo *)netInfo sorter:(id<QNRecordSorter>)sorter;


- (instancetype)putHosts:(NSString *)domain ipv4:(NSString *)ipv4;


- (instancetype)putHosts:(NSString *)domain ip:(NSString *)ip type:(int)type provider:(int)provider;


- (instancetype)putHosts:(NSString *)domain record:(QNRecord *)record provider:(int)provider;


+ (void)setGetAddrInfoBlock:(QNGetAddrInfoCallback)block;


+ (void)setDnsManagerForGetAddrInfo:(QNDnsManager *)dns;


+ (void)setIpStatusCallback:(QNIpStatusCallback)block;


+ (BOOL)needHttpDns;

@end

@interface QNDnsManager (NSURL)

- (NSURL *)queryAndReplaceWithIP:(NSURL *)url;
@end
