//
//  QNHex.h
//  DNS Lookup server
//
//

#import <Foundation/Foundation.h>

char *qn_encodeHexData(char *output_buf, const char *data, int data_size, BOOL up);

@interface QNHex : NSObject

+ (NSString *)encodeHexData:(NSData *)data;
+ (NSString *)encodeHexString:(NSString *)str;

+ (NSData *)decodeHexString:(NSString *)hex;
+ (NSString *)decodeHexToString:(NSString *)hex;

@end
