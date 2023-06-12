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

int main (int argc, char *argv[])
{
    int listenfd=0, connfd=0;
    struct sockaddr_in serv_addr;

    char buffer[1025];
    time_t tick;

    memset(&serv_addr, 0, sizeof(serv_addr));
    memset(&buffer, 0, sizeof(buffer));

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error: Could not create socket \n");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000);

    if ((bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) {
        fprintf(stderr, "Error: Could not bind address \n");
        return 1;
    }

    if ((listen(listenfd, 10)) < 0) {
        fprintf(stderr, "Error: Could not start listening in socket \n");
        return 1;
    }

    while (1) {
        printf("listening\n");
        connfd = accept(listenfd, NULL, NULL);

        tick = time(NULL);
        snprintf(buffer, sizeof(buffer), "%.24s\r\ntestiiiing\n", ctime(&tick));

        write(connfd, buffer, sizeof(buffer));

        printf("test\n");
        sleep(1);
    }
    
    return 0;
}
