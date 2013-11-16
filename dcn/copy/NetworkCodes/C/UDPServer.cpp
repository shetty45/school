/*
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <ctype.h>


void Capitalize(char * s) {
	for (int i = 0; i < strlen(s); i++)
	{
		if (islower(s[i]))
			s[i]=toupper(s[i]);
	}
}

int main(void)
{
	const int BUFLEN=512;
	const int NPACK=10;
	const int PORT=9930; //Todo: change this to the port # that is written on your handout 
   // as we all run our servers on storm or erdos, we want to avoid using same port
   // number as other's server 

	struct sockaddr_in si_me, si_other;
	int s, i, slen=sizeof(si_other);
	int mesgLen;
   	char buf[BUFLEN];
   
	//create a UDP socket
  	if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
	{
		printf ("Error creating socket\n");
    		return 1;
	}

	//bind  the socket to port number 
    	memset((char *) &si_me, 0, sizeof(si_me));
    	si_me.sin_family = AF_INET;
        si_me.sin_port = htons(PORT);
        si_me.sin_addr.s_addr = htonl(INADDR_ANY);
        if (bind(s, (struct sockaddr *) &si_me, sizeof(si_me))==-1)
	{
		printf ("error in bind\n");
		return 2;
	}

	mesgLen = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, (socklen_t*)&slen);
   	if (mesgLen==-1)
	{
    		printf("error in recvfrom()");
		return 3;
	}
	buf[mesgLen] = '\0';

    	printf("Received packet from %s:%d\nData: %s, length:%d\n\n", 
    		inet_ntoa(si_other.sin_addr), //client's IP
		ntohs(si_other.sin_port),  //client's port #
		buf, strlen(buf));

	Capitalize (buf);

	if (sendto (s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, slen)==-1)
	{
		printf ("error in sendto\n");
		return 4;
	}
    
   close(s);
   return 0;
}
