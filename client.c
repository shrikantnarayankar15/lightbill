/* <Remote Lightbill payment system>
    Copyright (C) <2015>  <Shrikant narayankar>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include <stdio.h>
#include "lightbill.h"
#include "user.h"
#include "client.h"
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
int main(int argc, char *argv[]) {
	system("clear");
	char buffer[MAXRCVLEN + 1];
	int len, mysocket;
	struct sockaddr_in dest; 
	mysocket = socket(AF_INET, SOCK_STREAM, 0);
	if(argv[1] == NULL) {
		printf("Enter Correct IP:");
		return;
	}
	memset(&dest, 0, sizeof(dest));                
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr(argv[1]);
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
		char atmno[16];
		send(mysocket, "hehe", 4, 0);
		printf("\n"); 
		printf("\t\t\tEnter your 14 no ATM:");
		scanf("%s", atmno);
		if(strlen(atmno) != 14) {
			printf("Enter Correct ATM no");
			return;
		}
		printf("\n");
		printf("\t\t\tEnter pin        :");
		char *c = getpass("");
		if(strlen(c) < 3) {
			printf("Enter Correct PIN no");
			return;
		}
		printf("\n\n");
		printf("\t\t\tPaid successfulyy");
	}
	printf("\n");
	close(mysocket);
	return EXIT_SUCCESS;
}
char displayInfo(allinfo a) {
	char y;
	if(a.b.paid_y_n == 'y') {
		printf("\t\t\tAlready Paid");
		getpass("");
		exit(0);
	}
	time_t now;
	time(&now);
	time_t t = time(NULL);
	struct tm *ts = localtime(&t);
	char date[20];
	strftime(date, 20, "%Y:%m:%d", ts);
	if(strcmp(a.b.end_date, date) < 0) {
		a.b.curr_bill = a.b.curr_bill + 10.0;
	}		
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

