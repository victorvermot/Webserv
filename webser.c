#include "stdio.h"
#include "sys/socket.h"
#include "sys/types.h"
#include "signal.h"
#include "stdlib.h"
#include "unistd.h"
#include "arpa/inet.h"
#include "errno.h"
#include "fcntl.h"
#include "sys/time.h"
#include "netdb.h"
#include "string.h"

#define SERVER_PORT 18000
#define MAXLINE 4096
#define SA struct sockaddr

void ft_quit(char *msg)
{
    printf("%s\n", msg);
    exit(0);
}

int main()
{
    int listenfd, connfd, n;
    struct sockaddr_in servaddr;
    u_int8_t        buff[MAXLINE + 1];
    u_int8_t        recvline[MAXLINE + 1];

    // creates a new socket : AF_INET = internet socker SOCK_STREAM = Tcp stream socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        ft_quit("Lol");
    
    // Set up the address to be listened to
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERVER_PORT);


    // We associate the address to the socket
    if ((bind(listenfd, (SA *)&servaddr, sizeof(servaddr))) < 0)
        ft_quit("Lol");
    
    // We say that we want to listen to this address
    if ((listen(listenfd, 10)) < 0)
        ft_quit("Lol3");

    while (1)
    {
        struct sockaddr_in addr;
        socklen_t addr_len;

        printf("Waiting for a connection on port %d\n", SERVER_PORT);
        fflush(stdout);
        // the code will wait until someone conncets to the port and then will return connfd
        connfd = accept(listenfd, NULL, NULL);

        memset(recvline, 0, MAXLINE);

        while ( (n = read(connfd, recvline, MAXLINE - 1)) > 0)
        {
            if (recvline[n - 1] == '\n')
                break;
            memset(recvline, 0, MAXLINE);
        }
        if (n < 0)
            ft_quit("Lol4");
        snprintf((char *)buff, sizeof(buff), "HTTP/1.0 200OK\r\n\r\nHello");
        write(connfd, (char *)buff, strlen((char*)buff));
        close(connfd);
    }
}
