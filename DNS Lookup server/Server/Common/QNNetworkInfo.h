//
//  QNNetworkInfo.h
//  DNS Lookup server
//
//

#import <Foundation/Foundation.h>

extern const int kQNNO_NETWORK;
extern const int kQNWIFI;
extern const int kQNMOBILE;

extern const int kQNISP_GENERAL;
extern const int kQNISP_CTC;
extern const int kQNISP_DIANXIN;
extern const int kQNISP_CNC;
extern const int kQNISP_LIANTONG;
extern const int kQNISP_CMCC;
extern const int kQNISP_YIDONG;
extern const int kQNISP_OTHER;

@interface QNNetworkInfo : NSObject

@property (nonatomic, readonly) int networkConnection;
@property (nonatomic, readonly) int provider;

- (instancetype)init:(int)connecton provider:(int)provider;

- (BOOL)isEqual:(id)other;
- (BOOL)isEqualToInfo:(QNNetworkInfo *)info;

+ (instancetype)noNet;

+ (instancetype)normal;

+ (BOOL)isNetworkChanged;

+ (NSString *)getIp;

@end
