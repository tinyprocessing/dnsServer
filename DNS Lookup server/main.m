//
//  main.m
//  DNS Lookup server
//
//  Created by Michael Safir on 28.12.2022.
//

#import <Foundation/Foundation.h>

#import "QNDomain.h"
#import "QNRecord.h"
#import "QNResolver.h"
#import "QNResolverDelegate.h"
#import "QNIP.h"
#import "QNDnsManager.h"
#import "QNDnsUdpResolver.h"

#import "QNHosts.h"
#import "QNNetworkInfo.h"

#import "QNResolverDelegate.h"
#import "QNTxtResolver.h"

NSString* getTypeName(int type) {
    if (type == 1) {
        return @"A";
    }
    if (type == 28) {
        return @"AAAA";
    }
    if (type == 1) {
        return @"CName";
    }
    if (type == 16) {
        return @"TXT";
    }
    
    if (type == -1) {
        return @"Forever TTL";
    }
    
    return @"-";
}

int main(int argc, const char * argv[]) {
    
    NSString *host = @"";
    NSString *port = @"";
    NSString *hostsPath = @"";
    NSString *dns = [QNResolver systemDnsServer];
  
    BOOL http = NO;
    
    // i = 1 to ignore xcode path
    for (int i = 1; i < argc-1; i+=2){
        NSString* command = [NSString stringWithUTF8String: argv[i]];
        NSString* argument = [NSString stringWithUTF8String: argv[i+1]];
        
        if ([command rangeOfString:@"-address"].location == 0) {
            host = argument;
        }
        
        if ([command rangeOfString:@"-port"].location == 0) {
            port = argument;
        }
        
        if ([command rangeOfString:@"-hosts"].location == 0) {
            hostsPath = argument;
        }
        
        if ([command rangeOfString:@"-server"].location == 0) {
            dns = argument;
        }
    }
    
    if ([hostsPath isEqual: @""]){
        hostsPath = @"/etc/hosts";
    }
    
    if ([host isEqual: @""]){
        NSLog(@"You need to provide hostname: -address <example.com>");
        return 1;
    }
        
    NSLog(@"Your primary dns server is: %@", dns);
    
    //custom hosts
    
    NSFileManager *fileManager;
    NSData *dataBuffer;
    NSArray *allLinedHosts;
    
    // ready hosts file if exists
    fileManager = [NSFileManager defaultManager];
    if ([fileManager fileExistsAtPath: hostsPath ] == YES){
        dataBuffer = [fileManager contentsAtPath: hostsPath ];
        NSString *stringHosts = [[NSString alloc] initWithData:dataBuffer encoding:NSUTF8StringEncoding];
        allLinedHosts = [stringHosts componentsSeparatedByCharactersInSet: [NSCharacterSet newlineCharacterSet]];
    }
    
    if (http == YES){
        // sync
        @autoreleasepool {
            id<QNResolverDelegate> resolver = [[QNResolver alloc] initWithAddress: dns];
            NSArray *records = [resolver query:[[QNDomain alloc] init: host] networkInfo:nil error:nil];
            records = [resolver query:[[QNDomain alloc] init: host] networkInfo:nil error:nil];
            for (QNRecord *record in records) {
                NSLog(@"%@ == server http sync: %@, type is %@, ttl is %d", host, [record value], getTypeName([record type]), [record ttl]);
            }
        }
    }
    
    QNHosts *hosts = [[QNHosts alloc] init];
    for (NSString* line in allLinedHosts) {
        if ([line rangeOfString:@"#"].location == NSNotFound) {
            NSString* lineTrimmed = [line stringByReplacingOccurrencesOfString:@"\t"
                                                                    withString:@" "];
            NSArray *array = [lineTrimmed componentsSeparatedByString:@" "];
            if (array.count == 2){
                [hosts put:array[1] record:[[QNRecord alloc] init:array[0] ttl:120 type:kQNTypeA source:QNRecordSourceUnknown]];
            }
        }
    }
    QNNetworkInfo *info = [QNNetworkInfo normal];
    NSArray<QNRecord *> *array = [hosts query:[[QNDomain alloc] init: host] networkInfo:info];
    if (array.count != 0){
        for (QNRecord *record in array) {
            NSLog(@"%@ == found with hosts path %@ : %@, type is %@, ttl is %d", host, hostsPath, [record value], getTypeName([record type]), [record ttl]);
        }
    }else{
        NSError *err = nil;
        // via UDP async
        // used dispatch_semaphore
        NSArray *typeArray = @[@(kQNTypeA), @(kQNTypeAAAA), @(kQNTypeCname), @(kQNTypeTXT)];
        for (NSNumber *type in typeArray) {
            QNDnsUdpResolver *server = [QNDnsUdpResolver resolverWithServerIP: dns recordType:type.intValue timeout:5];
            NSArray *records = [server query:[[QNDomain alloc] init:host] networkInfo:nil error:&err];
            for (QNRecord *record in records) {
                NSLog(@"%@ == server udp async: %@, type is %@, ttl is %d", host, [record value], getTypeName([record type]), [record ttl]);
            }
        }
        
        id<QNResolverDelegate> resolver = [[QNTxtResolver alloc] initWithAddress: dns];
        NSArray *records = [resolver query:[[QNDomain alloc] init: host] networkInfo:nil error:nil];
        for (QNRecord *record in records) {
            NSLog(@"%@ == txt record value: %@, ttl: %d", host,  [record value], [record ttl]);
        }
    }
    
    return 0;
}
