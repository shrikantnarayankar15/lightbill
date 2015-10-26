#include "db.h"
#include <unistd.h>
#include "user.h"
#include <string.h>
void verifyAdmin() {
	system("clear");
	char name[20], *pass;
	char *oname = "shrikant", *opass = "hehe";
	printf("\n\t\t-----------Login-----------\n\n");
	printf("\n\t\tEnter Username:");
	scanf("%s", name);
	printf("\n\t\tEnter Password:");
	pass = getpass("");
	if((strcmp(oname, name) == 0) && (strcmp(opass, pass) == 0)) {
		printf("\n\n\t\t\tLogin Successful");
		return;
	}
	else {
		printf("\n\n\t\tUnauthorized");
		exit(0);
	}
}
void addUser() {
	getchar();
	char id[4], name[20], bill[8];
	char unit[8], cur_unit[10], prev_unit[10];
	db a;
	init(&a);
	selectdb(&a);
	printf("\n");
	printf("\tEnter ID:\t");
	scanf("%s", id);
	printf("\tEnter Name:\t");
	scanf("%s", name);
	printf("\tEnter bill:\t");
	scanf("%s", bill);
	printf("\tEnter Unit:\t");
	scanf("%s", unit);
	printf("\tEnter cur_unit:\t");
	scanf("%s", cur_unit);
	printf("\tEnter prev_unit:\t");
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
	mysql_query(a.con, queryForPaid);
	closedb(&a);	
}
void printmenu() {
	printf("\n\n");
	printf("\t\t\t\tAdmin Section\n\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\t1. Add a User\n\n\n");
	printf("\t\t\t2. Payment Table\n\n\n");
	printf("\t\t\t3. exit\n");
	printf("\t\t\t-------------------------------------\n");
}	
void paymentTable() {
	db a;
	init(&a);
	selectdb(&a);
	result(&a, "select * from paidusers");
	MYSQL_ROW row;
	printf("\t_______________________________________");
	printf("\n\n\t|\tID\t|\tPaid\t|");
	while((row = mysql_fetch_row(a.res))){
		printf("\n\t|\t%d\t|\t%s\t|", atoi(row[0]), row[1]);
	}
	printf("\n\t_______________________________________");
	closedb(&a);		
}
int main() {
	verifyAdmin();
	getpass("");				
	int choice;
	do {		
		system("clear");				
		printmenu();
		scanf("%d", &choice);
		switch(choice)	{
			case 1:
				system("clear");
				addUser();
				printf("Successfully added");
				getpass("");
				break;
			case 2:
				system("clear");
				paymentTable();
				getpass("");
				break;
			case 3:
				exit(0);
		}
	}while(1);
	return 0;
}	
