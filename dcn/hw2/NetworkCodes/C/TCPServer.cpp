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

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 

    char sendBuff[1025];
    time_t ticks; 

    //Create a TCP socket 
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    //bind the socket to port 5000, i.e., the socket will be listening on port 5000
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 
    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    //listen for new connection request 
    listen(listenfd, 10); 

    while(1)
    {
        //accept a new connection request, and return a new socket 
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 

        //Todo: modify it so that 
        // 1. read from the socket, 
        // 2. write the message back to the client 
        //get current system time, and write the time to the socket 
        ticks = time(NULL);
        snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
        write(connfd, sendBuff, strlen(sendBuff)); 

        //close the socket 
        close(connfd);
        sleep(1);
     }
}
