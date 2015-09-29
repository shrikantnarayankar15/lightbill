#include "db.h"
void paybill(char *ID);
void displaybill() {
	MYSQL_ROW row;
	db a;
	init(&a);
	selectdb(&a);
	char query[] = "select * from users where id=";
	char id[10];
	printf("\t\tEnter ID: ");
	scanf("%s", id);
	strcat(query, id);
	result(&a, query);
	row = mysql_fetch_row(a.res);
	printf("----------------------------------------------------\n");
	printf("\t\t\tID       \t:\t\t%d\n", atoi(row[0]));
	printf("\t\t\tName     \t:\t\t%s\n", row[1]);
	printf("\t\t\tbill     \t:\t\t%s\n", row[2]);
	printf("\t\t\tunits    \t:\t\t%d\n", atoi(row[3]));
	printf("\t\t\tcur_unit \t:\t\t%d\n", atoi(row[4]));
	printf("\t\t\tprev_unit\t:\t\t%d\n", atoi(row[5]));
	printf("----------------------------------------------------\n");
}
