#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/un.h>
#include <stdarg.h>
#include <syslog.h>
#include <unistd.h>
#include <string.h>


#define BUFSIZE 1500

typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

typedef struct timeval Timeval;
typedef struct sockaddr Sockaddr;

/* the following are a few definitions from Stevens' unp.h */


#define max(a,b) ((a) > (b) ? (a) : (b))

extern int max_ttl;
extern Sockaddr *sasend;    /* socket addresses for various purposes */
extern Sockaddr *sarecv;
extern Sockaddr *salast;
extern Sockaddr *sabind;
extern socklen_t salen;                    /* length of a socket address */
extern char sendbuf[BUFSIZE];
extern Rec *rec;
extern int datalen;         /* length of the data in a datagram */





// declared in trout.c
void loop_ttl();
int send_probes (int ttl);
void send_dgram (int ttl);
void print_report();
double time_to_double (Timeval *time);
void sub_tv (Timeval *plus, Timeval *minus, Timeval *res);
int recv_dgram();
int process_ip (struct ip *ip, int len);
void sig_alrm (int signo);
