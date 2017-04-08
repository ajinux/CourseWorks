#include <netinet/in.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#define MAXLINE 20
#define SERV_PORT 7134

main(int argc, char** argv)
{
    int maxfdp1;
    fd_set rset;
    char sendline[MAXLINE], recvline[MAXLINE];
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 2) {
        printf("usage tcpcli <ipaddress>");
        return;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);

    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    
    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    printf("\n enter data to be send");

    while (fgets(sendline, MAXLINE, stdin) != NULL) {
        write(sockfd, sendline, MAXLINE);
        printf("\n line send to server is %s", sendline);
        read(sockfd, recvline, MAXLINE);
        printf("line recieved from the server %s", recvline);
    }
    exit(0);
}