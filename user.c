#include "user.h"
#include "lightbill.h"
#include <stdio.h>
#include <stdlib.h>
void adduser() {
	FILE *fp;
	//creating file if not exist
	fp=fopen("userdata.txt","a");
	fclose(fp);
	// creation of file end
	user obj;
	fflush(stdin);
	printf("\n\n");
	printf("\t\t\tEnter ID: ");
	scanf("%s", obj.id);	
	fflush(stdin);
	printf("\t\t\tEnter Name: ");
	scanf("%s", obj.name);
	printf("\t\t\tEnter Age: ");
	scanf("%s", obj.age);
	printf("\t\t\tEnter phone_no:");
	scanf("%s", obj.phone_no);
	fflush(stdin);
	printf("\t\t\tAddress:");
	scanf("%s", obj.addr);
	printf("\t\t\tEmail address:");
	scanf("%s", obj.email);
	printf("\n");
	if(verifyid(atoi(obj.id)) == 0) {
		fp=fopen("userdata.txt","a");
		fwrite(&obj, sizeof(obj), 1, fp);
		init_bill(atoi(obj.id));
		fflush(stdin);
		fclose(fp);
	}
	else {
		printf("\n\n\t\t\tAlready Present");
	}
}
user finduser(int id) {
	FILE *fp;
	user obj, temp;
	int i = 0;
	fp = fopen("userdata.txt","r");
	while(fread(&obj, sizeof(obj), 1, fp)==1){
		if(id == atoi(obj.id)) {
			temp = obj;
		}
	}
	fclose(fp);
	return temp;
}
void remove_user(int id) {
	FILE *fp, *ft;
	user list;
	fp = fopen("userdata.txt", "r");
	ft = fopen("temp1.txt", "w");
	delete_bill(id);
io:	while(fread(&list, sizeof(list), 1, fp) == 1) {
		if(id == atoi(list.id)) {
			delete_bill(id);
			goto io;
		}
		fwrite(&list, sizeof(list), 1, ft);		
	}
	fclose(fp);
	fclose(ft);
	remove("userdata.txt");
	rename("temp1.txt","userdata.txt");
}
int verifyid(int id) {
	FILE *fp;
	user obj;
	int i = 0;
	fp = fopen("userdata.txt","r");
	while(fread(&obj,sizeof(obj),1,fp)==1){
		if(id == atoi(obj.id))
			return 1;
	}
	return 0;
}
void showusers(int argc, char *argv[]) {
	FILE *fp;
	fp = fopen("userdata.txt","r");
	printf("      ID      |      Name      |      Address      |      Age       |      phoneno      |      Email ID      |\n");
	int count = 0;
	user ar[100];
	user list;	
	while(fread(&list,sizeof(list),1,fp)==1){
		ar[count] = list;
		count++;
	}	
	printf("%d", count);
	int i, j;
	for(i = 0;i < count; i++) {
		for(j = i + 1; j < count; j++) {
			if(ar[i].id > ar[j].id) {
				user temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
		}
	}
	for(i = 0; i < count; i++)
        	printf("\n|      %s      |%20s|%20s|      %s      |   %10s   |  %s  \n",ar[i].id,ar[i].name,ar[i].addr ,ar[i].id, ar[i].phone_no, ar[i].email);
}
void display_user(user a) {
	printf("\n\n");
	printf("\t\t----------------------------------------------------\n");
	printf("\t\t----------------------------------------------------\n");
	printf("\t\t\tID       \t:\t\t%s\n", a.id);
	printf("\t\t\tName     \t:\t\t%s\n", a.name);
	printf("\t\t\tAddress   \t:\t\t%s\n", a.addr);
	printf("\t\t\tAge      \t:\t\t%s\n", a.age);
	printf("\t\t\tPhone_No   \t:\t\t%s\n", a.phone_no);
	printf("\t\t\tEmail       \t:\t\t%s\n", a.email);
	printf("\t\t----------------------------------------------------\n\n\n\n");
}
