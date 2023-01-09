#include "csapp.h"

void echo(int connfd);

int main(int argc, char **argv)
{
	int listenfd, connfd, port;
	socklen_t clientlen;
	struct sockaddr_storage clientaddr;	/* Enough space for any address */
	char client_hostname[MAXLINE], client_port[MAXLINE];

	if (argc != 2) {
		
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}

	port = atoi(argv[1]);

	listenfd = Open_listenfd(port);

	while (1) {
	
		clientlen = sizeof(struct sockaddr_storage);
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		getnameinfo((SA *) &clientaddr, clientlen, client_hostname, MAXLINE, 
				client_port, MAXLINE, 0);
		printf("Connected to (%s, %s)\n", client_hostname, client_port);
		echo(connfd);
		Close(connfd);
	}

	exit(0);
}


