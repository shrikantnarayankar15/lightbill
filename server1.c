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
 
int main(int argc, char *argv[])
{
    char* msg = "Connected";
	MYSQL_ROW row;
	char id[10];
    struct sockaddr_in dest; /* socket info about the machine connecting to us */
    struct sockaddr_in serv; /* socket info about our server */
    int mysocket;            /* socket used to listen for incoming connections */
    socklen_t socksize = sizeof(struct sockaddr_in);

    memset(&serv, 0, sizeof(serv));           /* zero the struct before filling the fields */
    serv.sin_family = AF_INET;                /* set the type of connection to TCP/IP */
    serv.sin_addr.s_addr = htonl(INADDR_ANY); /* set our address to any interface */
    serv.sin_port = htons(PORTNUM);           /* set the server port number */    
	mysocket = socket(AF_INET, SOCK_STREAM, 0);
	bind(mysocket, (struct sockaddr *)&serv, sizeof(struct sockaddr));
	listen(mysocket, 1);	
	char temp[1000];
	int len;
	int consocket;
	char error[100];
	static char idp[3];
	while(1) {
		consocket = accept(mysocket, (struct sockaddr *)&dest, &socksize);
		perror(error);
		db a;
		userobj a1;
		init(&a);
		selectdb(&a);	
		printf("%d", len);
		char query[] ={"select * from users where id="};    
		len = recv(consocket, temp, 3, 0);
		char temp1[len];
		strcpy(temp1, temp);
		perror(error);
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
		printf("incoming connn %s\n", inet_ntoa(dest.sin_addr));
		send(consocket, &a1, sizeof(a1), 0);
	 	len = recv(consocket, &temp, 4, 0);
		if(len){
			char querypaid[] = "update paidusers set paid = 'y' where id =";
			strcat(querypaid, idp);
			mysql_query(a.con, querypaid);
		}
		perror(error);
		close(consocket);
	}		
	close(mysocket);
	return EXIT_SUCCESS;
}

