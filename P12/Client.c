#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

// Prints error message, given by msg parameter
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockFd, portNo, n;
    struct sockaddr_in servAddr;
    struct hostent *server;
    char buffer[256];

    // Checks if all arguments were given
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    // Gets data from arguments
    server = gethostbyname(argv[1]);
    portNo = atoi(argv[2]);

    // Opens socket
    sockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockFd < 0) 
        error("ERROR opening socket");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    
    bcopy((char *)server->h_addr, 
         (char *)&servAddr.sin_addr.s_addr,
         server->h_length);
    servAddr.sin_port = htons(portNo);
    
    // Checks if it was able to connect to socket
    if (connect(sockFd,(struct sockaddr *) &servAddr,sizeof(servAddr)) < 0) {
        error("ERROR connecting");
    }

    // Asks for message to send
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    // Sends message through socket
    n = write(sockFd,buffer,strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockFd,buffer,255);

    // Reads what is returned in the socket
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);
    close(sockFd);
    return 0;
}