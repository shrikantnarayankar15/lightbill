#include <stdio.h>
#include "lightbill.h"
#include "user.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define MAXRCVLEN 500
#define PORTNUM 2300 
typedef struct allinfo {
	user a;
	lightbill b;
}allinfo;
char displayInfo(allinfo a);
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
	allinfo a;
	system("clear");
	send(mysocket, msg, strlen(msg), 0); 
	len = recv(mysocket, &a, sizeof(a), 0);
	char y = displayInfo(a);
	if(y == 'y'){
		int atmno;
		send(mysocket, "hehe", 4, 0);
		printf("\n"); 
		printf("\t\t\tEnter your ATM no:");
		scanf("%d", &atmno);
		printf("\n");
		printf("\t\t\tEnter pin        :");
		char *c = getpass("");
		printf("\n\n");
		printf("\t\t\tPaid successfulyy");
	}
	printf("\n");
	close(mysocket);
	return EXIT_SUCCESS;
}

char displayInfo(allinfo a) {
	char y;
	time_t now;
	time(&now);
	printf("Date:  %s", ctime(&now));
	printf("\n\n");
	printf("\t\t----------------------------------------------------\n");
	printf("\t\t----------------------------------------------------\n");
	printf("\t\t\tID       \t:\t\t%d\n", a.b.id);
	printf("\t\t\tName       \t:\t\t%s\n", a.a.name);
	printf("\t\t\tcurr_unit     \t:\t\t%d\n", a.b.curr_unit);
	printf("\t\t\tprev_unit   \t:\t\t%d\n", a.b.prev_unit);
	printf("\t\t\tcurr_bill \t:\t\t%f\n", a.b.curr_bill);
	printf("\t\t\tprev_bill   \t:\t\t%f\n", a.b.prev_bill);
	printf("\t\t\tmonth       \t:\t\t%s\n", a.b.month);
	printf("\t\t\tEND_Date \t:\t\t%s\n", a.b.end_date);
	printf("\t\t----------------------------------------------------\n\n\n\n");
	printf("\t\t\tDo You want To pay Bill : 'y' Or 'n'");
	scanf(" %c", &y);
	return y;
}
