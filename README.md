DNS server for searching type A, AAAA, TXT, CName records on iOS and macOS platforms

This code is a test case for Deloitte and meets the following requirements: 

Asynchronous DNS server processes the incoming DNS-queries via UDP and performs name resolution asynchronously using MacOS asynchronous Network API.
Lookup order:
1. Shared custom DNS records from a file.
2. Shared cache of resolved addresses.
3. Name resolution using MacOS asynchronous Network API.
 
Requirements for DNS server:
1. The server should be written in Obj-C.
2. The server should take the command-line arguments: address, port, path to file with custom DNS entries, etc.
3. The server should load custom DNS records map from a file at startup (file format like /etc/hosts).
4. The server should support multiple A-records.
5. The server should listen the UDP requests on the default port, but it can be specified using the command-line arguments.
6. The server should process DNS-requests asynchronously with configurable number of worker threads depending on the CPU cores amount.
7. The server should have a shared cache of resolved addresses with TTL.
8. The server should print information about DNS requests and resolved addresses.
 
Additional requirements for DNS server (will be a big plus):
1. The server should support multiple AAAA-records and CNAME-records.
2. Implement the functionality of DNS proxy server instead of MacOS Network API. In this case, DNS requests will be asynchronously sent to an external DNS server, the address of which can be specified in the command-line arguments.

For anyone who wants to get a job at Deloitte - this company cheats and takes your test assignments, don't waste your time and use ready-made solutions. Thank you. 

