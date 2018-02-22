#include "packet_sniffer.h"

int raw_sockfd;
struct sockaddr_in src, dest;
int ip = 0, tcp = 0, icmp = 0;
FILE* logfile_fp = NULL;
int main()
{
        int saddr_size, data_size;
        struct sockaddr saddr;
        struct in_addr in;
        char buffer[MAX_BUFFER_SIZE];
        logfile_fp = fopen("network_packets.log","w");
        if (!logfile_fp)
        {
	   printf("Cannot open network_packets log file\n");
	   exit(1);
	}
        raw_sockfd = socket(AF_INET,SOCK_RAW,IPPROTO_TCP);
        if (raw_sockfd < 0)
	{
		printf("Cannot create the raw socket\n");
		exit(1);
	}

	while (1)
	{
		saddr_size = sizeof(saddr);
		data_size = recvfrom(raw_sockfd,buffer,MAX_BUFFER_SIZE,0,&saddr,&saddr_size);
                if (data_size < 0)
                {
			printf("Failed to read packets\n");
			return 1;
                }
		process_packet(buffer,data_size);
	}
        close(raw_sockfd);
	printf("Done\n");
	return 0;
}
