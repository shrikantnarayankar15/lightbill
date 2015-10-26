#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "db.h"
#include "user.h"
#define PORTNUM 2300 
int main(int argc, char *argv[]) {
	char* msg = "Connected";
	MYSQL_ROW row;
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
	static char idp[3];
	while(consocket){
		char temp[1000], er[20];
		userobj a1;
		db a;
		init(&a);
		selectdb(&a);
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
		strcat(query, temp1);
		result(&a, query);
		row = mysql_fetch_row(a.res);
		strcpy(idp, row[0]);
		a1.id = atoi(row[0]);
		strcpy(a1.name, row[1]);
		a1.bill = atof(row[2]);
		a1.unit = atoi(row[3]);
		a1.cur_unit = atoi(row[4]);
		a1.prev_unit = atoi(row[5]);
		printf("hehe");
		send(consocket, &a1, sizeof(a1), 0);
	 	len = recv(consocket, &temp, 4, 0);
		if(len){
			char querypaid[] = "update paidusers set paid = 'y' where id = ";
			strcat(querypaid, idp);
			mysql_query(a.con, querypaid);
		}
		close(consocket);
		mysql_close(a.con);
		consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);			
	}	
	close(mysocket);
	return EXIT_SUCCESS;
}

