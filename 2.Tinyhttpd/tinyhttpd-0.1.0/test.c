#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(int argc, char const *argv[])
{

    int fd;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        perror("bind");
        exit(-1);
    }


    if (ntohs(addr.sin_port) == 0)
    {
        socklen_t addrlen;
        addrlen = sizeof(addr);
        if (getsockname(fd, (struct sockaddr *)&addr, &addrlen) == -1)
        {
            perror("getsockname");
            exit(-1);
        }

        printf("addr: %d, port : %d, familt: %d\n", ntohl(addr.sin_addr.s_addr), ntohs(addr.sin_port), addr.sin_family);
    }

    if (listen(fd, 5) < 0)
    {
        perror("listen");
        exit(-1);
    }

    return 0;
}
