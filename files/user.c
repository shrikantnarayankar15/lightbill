#include "db.h"
#include <unistd.h>
void paybill(char *ID, double bill);
void lightbilldisplay() {
	system("clear");
	char id[10];
	printf("\t\tMSEBC LIGHTBILL\n");
	printf("\tEnter ID:");
	scanf("%s", id);
	db a;
	init(&a);
	selectdb(&a);
	char query[] = "select * from users where id=";
	strcat(query, id);
	result(&a, query);
	MYSQL_ROW row;
	int i;
	row = mysql_fetch_row(a.res);
	printf("\n\n\n");
	printf("\tID                    |\t\t %d\n", atoi(row[0]));
	printf("\tname                  |\t\t %s\n", row[1]);
	printf("\tbill                  |\t\t %lf\n", atof(row[2]));
	printf("\tunits                 |\t\t %d\n", atoi(row[3]));
	printf("\tcurrunits             |\t\t %d\n", atoi(row[4]));
	printf("\tprevunits             |\t\t %d\n", atoi(row[5]));
	printf("\n");
	printf("\tDo you want to pay Bill? Y Or N:  ");
	char c;
	scanf(" %c", &c);
	if(c == 'Y' || c == 'y') {
		paybill(row[0], atof(row[2]));
	}
	else{
		system("clear");
		printf("\t\tQuiting\n\n");
	}
	return;
}
void paybill(char *ID, double bill) {
	int cd, pass;
	system("clear");
	printf("\n\n");
	printf("---------------------------------------------------\n");
	printf("\t\tEnter Credit Card No:");	
	scanf("%d", &cd);
	printf("---------------------------------------------------\n");
	printf("\t\tEnter Pin:");
	scanf("%d", &pass);
	printf("---------------------------------------------------\n");
	printf("\t\tAre You Confirm? y or n: ");
	char con;
	scanf(" %c", &con);
	if(con == 'y') {
//		trasact(ID);
		printf("\n\n");
		printf("\7 Your transaction is succesfull\n");
		printf("enter you have paid %lf Rs.\n\n\n", bill);
	}
}
