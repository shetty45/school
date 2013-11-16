#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


int main(int argc, char * argv[])
{
	const int BUFLEN=512;
	const int NPACK=10;
	const int PORT=9930;  //TODO: change 9930 to the port # you choose to use 
	char SRV_IP[56]="150.108.68.26"; //Todo: change the 999.999. to the IP address 
	//of the machine where the UDPServer is running on 
	string lineBuf;

	struct sockaddr_in si_other, pkt_addr;
	int s, i, slen=sizeof(si_other);
	char buf[BUFLEN];
     
	if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
   {
		printf ("errro in socket\n");
		return 2;
	}

	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);

	if (inet_aton(SRV_IP, &si_other.sin_addr)==0) {
    	fprintf(stderr, "inet_aton() failed\n");
    	exit(1);
	}
	
	cout <<"Enter a line:";
	getline (cin, lineBuf);
	strcpy (buf, lineBuf.c_str());

	if (sendto(s, buf, strlen(buf), 0, (struct sockaddr *)&si_other, slen)==-1)
	{
		printf ("error in sendto\n");
		return 1;
	}

	if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *)&pkt_addr, (socklen_t*)&slen)==-1)
        {
                printf("error in recvfrom()");
                return 3;
        }
        printf("Received packet from %s:%d\nData: %s\n\n",
                inet_ntoa(pkt_addr.sin_addr), //client's IP
                ntohs(pkt_addr.sin_port),  //client's port #
                buf);
	
	
    
	close(s);
	return 0;
}
