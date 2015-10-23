#include "db.h"
#include "user.h"
#include <string.h>
int main() {
	char id[4], name[20], bill[8];
	char unit[8], cur_unit[10], prev_unit[10];
	db a;
	init(&a);
	selectdb(&a);
	printf("Enter ID:\t");
	scanf("%s", id);
	printf("Enter Name:\t");
	scanf("%s", name);
	printf("Enter bill:\t");
	scanf("%s", bill);
	printf("Enter Unit:\t");
	scanf("%s", unit);
	printf("Enter cur_unit:\t");
	scanf("%s", cur_unit);
	printf("Enter prev_unit:\t");
	scanf("%s", prev_unit);
	char query[] = {"insert into users values("};
	char queryForPaid[40];
	//for adding data to the db
	strcat(query, id);
	strcat(query, ",'");
	strcat(query, name);
	strcat(query, "',");
	strcat(query, bill);
	strcat(query, ",");
	strcat(query, unit);
	strcat(query, ",");
	strcat(query, cur_unit);
	strcat(query, ",");
	strcat(query, prev_unit);
	strcat(query, ");");
	mysql_query(a.con, query);
	// initially inserting the paid 'n' i.e. not paid
	strcpy(queryForPaid, "insert into paidusers values(");
	strcat(queryForPaid, id);
	strcat(queryForPaid, ",'n')");
	printf("%s", queryForPaid);
	mysql_query(a.con, queryForPaid);
	closedb(&a);
	return 0;
}	
