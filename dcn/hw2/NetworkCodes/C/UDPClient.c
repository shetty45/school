#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void diep(char *s)
{
	perror(s);
	exit(1);
}

int main(void)
{
     const int BUFLEN=512;
     const int NPACK=10;
     const int PORT=7019;
	struct sockaddr_in si_other;
     int s, i, slen=sizeof(si_other);
     char buf[BUFLEN];

     char SRV_IP[56]="150.108.68.26";
     
    //Create a UDP socket 
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
    	diep("socket");
    
    //Fill in the si_other with the server's IP addr, and port #
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);
    if (inet_aton(SRV_IP, &si_other.sin_addr)==0) {
    	fprintf(stderr, "inet_aton() failed\n");
    	exit(1);
    }
    
   for (i=0; i<NPACK; i++) {
	printf("Sending packet %d\n", i);
    	sprintf(buf, "This is packet %d\n", i);

	//send the string buf to the server at the given port 
    	if (sendto(s, buf, BUFLEN, 0, (struct socketaddr *)&si_other, slen)==-1)
    		diep("sendto()");
    }
    
    close(s);
    return 0;
}
