#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "lightbill.h"
#include "user.h"
#define PORTNUM 2300 
typedef struct allinfo {
	user a;
	lightbill b;
}allinfo;
int main(int argc, char *argv[]) {
	char* msg = "Connected";
	char id[10];
	struct sockaddr_in dest; 	
	struct sockaddr_in serv;
	int mysocket;           
	socklen_t socksize = sizeof(struct sockaddr_in);
	memset(&serv, 0, sizeof(serv));  
	serv.sin_family = AF_INET;       
	serv.sin_addr.s_addr = htonl(INADDR_ANY); 
	serv.sin_port = htons(PORTNUM);              
	mysocket = socket(AF_INET, SOCK_STREAM, 0);
	bind(mysocket, (struct sockaddr *)&serv, sizeof(struct sockaddr));
	listen(mysocket, 1);
	int consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);
	int len;
	allinfo h;
	static char idp[3];
	while(consocket){
		char temp[1000], er[20];
		lightbill a1;
		printf("%d", len);
		char query[] ="select * from users where id=";  
		len = recv(consocket, temp, 10, 0);
		char temp1[4];
		int i = 0;
		while(i < 3) {
			temp1[i] = temp[i];
			i++;
		}
		temp1[i] = '\0';
		h.b = find_bill(atoi(temp1));
		h.a = finduser(atoi(temp1));		
		send(consocket, &h, sizeof(h), 0);
	 	len = recv(consocket, &temp, 4, 0);
		if(len){
			pay_bill(atoi(temp1));
		}
		close(consocket);
		consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);					
	}	
	close(mysocket);
	return EXIT_SUCCESS;
}

