/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

// Prints error message, given by msg parameter
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockFd, newSockFd, portNo;
    socklen_t cliLen;
    char buffer[256];
    struct sockaddr_in servAddr, cliAddr;
    int n;

    // Checks if all arguments were given
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    // Gets data from argument
    portNo = atoi(argv[1]);

    // Opens socket
    sockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockFd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(portNo);
    if (bind(sockFd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
            error("ERROR on binding");
    }

    // Starts listening on socket
    listen(sockFd,5);
    cliLen = sizeof(cliAddr);
    newSockFd = accept(sockFd, 
                (struct sockaddr *) &cliAddr, 
                &cliLen);
    if (newSockFd < 0)
        error("ERROR on accept");
    bzero(buffer,256);

    // Reads sent data
    n = read(newSockFd,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    // Prints message sent
    printf("Here is the message: %s\n",buffer);

    // Sends back confirmation message
    n = write(newSockFd,"I got your message",18);
    if (n < 0) error("ERROR writing to socket");

    // Closes conection
    close(newSockFd);
    close(sockFd);
    return 0; 
}