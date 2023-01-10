//
//  QNResolv.h
//  DNS Lookup server
//
//

#ifndef QNResolv_h
#define QNResolv_h

extern BOOL isV6(NSString *address);

extern int setup_dns_server(void *res, NSString *dns_server, NSUInteger timeout);

#endif /* QNResolv_h */
