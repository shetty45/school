#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 
using namespace std;

int main(int argc, char *argv[])
{
    int sockfd = 0, n = 0;
    int stringLen;
    char readBuff[1024];
    char recvBuff[1024];
    struct sockaddr_in serv_addr; 
    char serverIP[256]="150.108.68.26";


    memset(recvBuff, '0',sizeof(recvBuff));
    //create a TCP socket 
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    //connect to server at port 5000 
    memset(&serv_addr, '0', sizeof(serv_addr)); 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000); 
    if(inet_pton(AF_INET, serverIP, &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    } 
    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
       return 1;
    } 

    //read a line from keyboard
    //stringLen = scanf ("%s", readBuff);
    cout <<"Enter a line:";
    cin >> readBuff;
    
    //write the line to socket 
    write (sockfd, readBuff, strlen(readBuff));
	
    //read (receive) from the socket, and write each message to terminal
    while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
        recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("\n Error : Fputs error\n");
        }
    } 

    if(n < 0)
    {
        printf("\n Read error \n");
    } 

    return 0;
}
