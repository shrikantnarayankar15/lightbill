#include "lightbill.h"
#include <unistd.h>
#include "user.h"
#include <stdio.h>
#include <stdlib.h>
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
void printmenu() {
	printf("\n\n");
	printf("\t\t\t------------WELCOME ADMIN--------------\n\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\t1. User Section\n\n\n");
	printf("\t\t\t2. Bill Section\n\n\n");
	printf("\t\t\t3. Start Server\n\n\n");
	printf("\t\t\t4. Exit\n");
	printf("\t\t\t-------------------------------------\n");
}	
void printmenu1() {
	printf("\n\n");
	printf("\t\t\t------------User Section--------------\n\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\t1. Add A User\n\n\n");
	printf("\t\t\t2. Remove A user\n\n\n");
	printf("\t\t\t3. Show all User\n\n\n");
	printf("\t\t\t4. exit\n");
	printf("\t\t\t-------------------------------------\n");
	int ch;
	printf("\n\n");
	printf("\t\t\tEnter Choice:");
	scanf("%d", &ch);
	switch(ch) {
		case 1:
			system("clear");
			adduser();
			break;
		case 2:
			system("clear");
			printf("\n\n");
			printf("\t\t\tEnter ID:");
			int id;
			scanf("%d", &id);
			remove_user(id);
			break;
		case 3:
			system("clear");
			showusers();
			break;
		case 4:
			return;		
	}
}	
void printmenu2() {
	printf("\n\n");
	printf("\t\t\t------------BILL SECTION--------------\n\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\t1. Generate bill\n\n\n");
	printf("\t\t\t2. Show all Bill\n\n\n");
	printf("\t\t\t3. Find a Bill\n\n\n");
	printf("\t\t\t4. Exit\n");
	printf("\t\t\t-------------------------------------\n");
	int ch;
	printf("\n\n");
	printf("\t\t\tEnter Choice:");
	scanf("%d", &ch);
	int id, unit;			
	switch(ch) {
		case 1:
			system("clear");
			printf("\n\n");
			printf("\t\t\tEnter ID:");
			scanf("%d", &id);
			printf("\t\t\tEnter Unit:");
			scanf("%d", &unit);
			generate_bill(id, unit);
			break;
		case 2:
			system("clear");
			show_bill();
			break;
		case 3:
			system("clear");
			lightbill l;
			printf("\n\n");
			printf("\t\t\tEnter ID:");
			scanf("%d", &id);
			l = find_bill(id);
			if(l.id) {
				display_lightbill(l);
			}
			else {
				printf("not present");
			}
			break;
		case 4:
			return;		
	}
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
				printmenu1();
				getpass("");						
				break;
			case 2:
				system("clear");
				printmenu2();
				getpass("");						
				break;
			case 3:
				system("clear");
				system("xterm -hold ./server &");
				printf("Server started");
				break;
			case 4:
				exit(0);
		}
	}while(1);
	return 0;
}	
