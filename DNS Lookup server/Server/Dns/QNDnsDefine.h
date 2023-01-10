//
//  QNDnsDefine.h
//  Doh
//
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, QNDnsOpCode) {
    QNDnsOpCodeQuery = 0,
    QNDnsOpCodeIQuery = 1,
    QNDnsOpCodeStatus = 2,
    QNDnsOpCodeUpdate = 5, 
};
