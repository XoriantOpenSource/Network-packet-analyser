/******************************
 * Declarations for 
 * IP header, 
 * TCP header,
 * UDP header, 
 * ICMP header
 ***************************/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <netinet/ip.h> 
#include <netinet/ip_icmp.h> 
#include <netinet/udp.h> 
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void process_packet(char* , int);
void print_ip_datagram(char*, int ); 
void print_tcp_packet(char*, int ); 
void print_udp_datagram(char*, int ); 
void print_icmp_packet(char*, int ); 
 
