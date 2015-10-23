#include <stdio.h>
#include "user.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define MAXRCVLEN 500
#define PORTNUM 2300 
void displayInfo(userobj a);
int main(int argc, char *argv[]) {
	system("clear");
	char buffer[MAXRCVLEN + 1];
	int len, mysocket;
	struct sockaddr_in dest; 
	mysocket = socket(AF_INET, SOCK_STREAM, 0);
	memset(&dest, 0, sizeof(dest));                
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = htonl(INADDR_LOOPBACK);  
	dest.sin_port = htons(PORTNUM);                 
	connect(mysocket, (struct sockaddr *)&dest, sizeof(struct sockaddr));
	char msg[3];
	printf("\t\t\t--------Welcome to LightBill Pay App-------\t\t");
	printf("\n\n\n");
	printf("\t\t\tEnter ID:");	
	scanf("%s", msg);
	userobj a;
	system("clear");
	send(mysocket, msg, strlen(msg), 0); 
	len = recv(mysocket, &a, sizeof(a), 0);
	displayInfo(a);
	char y;
	scanf(" %c", &y);
	if(y == 'y'){
			send(mysocket, "hehe", 4, 0); 
			printf("%c", y);
	}		
	close(mysocket);
   return EXIT_SUCCESS;
}
void displayInfo(userobj a) {
	printf("----------------------------------------------------\n");
	printf("\t\t\tID       \t:\t\t%d\n", a.id);
	printf("\t\t\tName     \t:\t\t%s\n", a.name);
	printf("\t\t\tbill     \t:\t\t%f\n", a.bill);
	printf("\t\t\tunits    \t:\t\t%d\n", a.unit);
	printf("\t\t\tcur_unit \t:\t\t%d\n", a.cur_unit);
	printf("\t\t\tprev_unit\t:\t\t%d\n", a.prev_unit);
	printf("----------------------------------------------------\n\n\n\n");
	printf("\t\t\tDo You want To pay Bill : 'y' Or 'n'");
}
