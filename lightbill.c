#include "lightbill.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
void init_bill(int id) {
	FILE *fp;
	//creating file if not exist
	fp=fopen("lightdata.txt","a");
	fclose(fp);
	// creation of file end
	lightbill obj;
	obj.id = id;
	obj.prev_bill = 0;
	obj.curr_bill = 0;
	obj.curr_unit = 0;
	obj.prev_unit = 0;
	strcpy(obj.end_date, "0");	
	strcpy(obj.month, "0");	
	obj.paid_y_n = 'n';
	fp = fopen("lightdata.txt","a");
	fwrite(&obj, sizeof(obj), 1, fp);
	fflush(stdin);
	fclose(fp);
}
lightbill find_bill(int id) {
	FILE *fp;
	lightbill obj, temp;
	int i = 0;
	fp = fopen("lightdata.txt","r");
	while(fread(&obj,sizeof(obj),1,fp)==1){
		if(id == obj.id) {
			temp = obj;
		}
	}
	fclose(fp);
	return temp;
}
void delete_bill(int id) {
	FILE *fp, *ft;
	fp = fopen("lightdata.txt", "r");
	ft = fopen("temp.txt", "w");
	lightbill list;
io:	while(fread(&list, sizeof(list), 1, fp) == 1) {
		if(id == list.id) {
			goto io;
		}
		fwrite(&list, sizeof(list), 1, ft);		
	}
	fclose(fp);
	fclose(ft);
	remove("lightdata.txt");
	rename("temp.txt","lightdata.txt");
}
void generate_bill(int id, int unit) {
	char *ar[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
	FILE *fp, *ft;
	time_t t = time(NULL);
	struct tm *ts = localtime(&t);
	ts->tm_mday += 7;
	float rate_per_unit = 0;
	if(unit < 0) {
		printf("Invalid unit");
		return;
	}
	if(unit <= 100)
		rate_per_unit = 3.76;
	if(101 <= unit >= 300)
		rate_per_unit = 7.21;
	if(301 <= unit >= 500)
		rate_per_unit = 9.95;
	if(501 <= unit >= 1000)
		rate_per_unit = 11.31;
	if(unit > 1000)
		rate_per_unit = 12.50;
	fp = fopen("lightdata.txt", "r");
	ft = fopen("temp.txt", "w");
	fflush(stdin);
	lightbill lt = find_bill(id);
	lightbill *obj = &lt;
	if(400 < obj->id > 0) {
		fclose(fp);
		fclose(ft);	
		return;
	}
	lightbill li;
	li.id = id;
	li.curr_unit = unit + (obj->curr_unit);
	li.prev_unit = obj->curr_unit;
	li.prev_bill = (obj->curr_bill);
	li.curr_bill = (unit) * rate_per_unit;
	strcpy(li.month, ar[ts->tm_mon]);
	char date[20];
	strftime(date, 20, "%Y:%m:%d", ts);
	strcpy(li.end_date, date);
	li.paid_y_n = 'n';	
	printf("\t\t\tThe generated Bill\n\n");	
	display_lightbill(li);
	int i = 0;
	lightbill list;
io:	while(fread(&list, sizeof(list), 1, fp) == 1) {
		if(id == list.id) {
			fwrite(&li, sizeof(li), 1, ft);
			goto io;
		}
		fwrite(&list, sizeof(list), 1, ft);		
	}
	fclose(fp);
	fclose(ft);
	remove("lightdata.txt");
	rename("temp.txt","lightdata.txt");
}
void pay_bill(int id) {
	FILE *fp, *ft;
	fp = fopen("lightdata.txt", "r");
	ft = fopen("temp3.txt", "w");
	fflush(stdin);
	lightbill lt = find_bill(id);
	lightbill *obj = &lt;
	lightbill li;
	li.id = id;
	li.curr_unit = (obj->curr_unit);
	li.prev_unit = obj->prev_unit;
	li.prev_bill = (obj->prev_bill);
	li.curr_bill = obj->curr_bill;
	strcpy(li.month, obj->month);
	strcpy(li.end_date, obj->end_date);
	li.paid_y_n = 'y';		
	int i = 0;
	lightbill list;
io:	while(fread(&list, sizeof(list), 1, fp) == 1) {
		if(id == list.id) {
			fwrite(&li, sizeof(li), 1, ft);
			goto io;
		}
		fwrite(&list, sizeof(list), 1, ft);		
	}
	fclose(fp);
	fclose(ft);
	remove("lightdata.txt");
	rename("temp3.txt","lightdata.txt");	
}
void show_bill() {
	FILE *fp;
	fp = fopen("lightdata.txt","r");
	printf("      ID\t| current_unit | prev_unit |   prev_bill   |\tcurr_bill\t|\tEND_DATE\t|\t paid\t\n");
	int count = 0;
	lightbill ar[100];
	lightbill list;	
	while(fread(&list,sizeof(list),1,fp)==1){
		ar[count] = list;
		count++;
	}	
	int i, j;
	for(i = 0;i < count; i++) {
		for(j = i + 1; j < count; j++) {
			if(ar[i].id > ar[j].id) {
				lightbill temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
		}
	}
	for(i = 0; i < count; i++)
        	printf("\n|     %d     |     %d     |     %d     |     %f     |     %f     |     %s     |     %s     |     %c     \n ",ar[i].id,ar[i].curr_unit,ar[i].prev_unit ,ar[i].prev_bill, ar[i].curr_bill, ar[i].end_date, ar[i].month,ar[i].paid_y_n);
	fclose(fp);
}
void display_lightbill(lightbill a) {
	printf("\n\n");
	printf("\t\t----------------------------------------------------\n");
	printf("\t\t----------------------------------------------------\n");
	printf("\t\t\tID       \t:\t\t%d\n", a.id);
	printf("\t\t\tcurr_unit     \t:\t\t%d\n", a.curr_unit);
	printf("\t\t\tprev_unit   \t:\t\t%d\n", a.prev_unit);
	printf("\t\t\tcurr_bill \t:\t\t%f\n", a.curr_bill);
	printf("\t\t\tprev_bill   \t:\t\t%f\n", a.prev_bill);
	printf("\t\t\tmonth       \t:\t\t%s\n", a.month);
	printf("\t\t\tEND_Date \t:\t\t%s\n", a.end_date);
	printf("\t\t----------------------------------------------------\n\n\n\n");
}
void show_bill_paid() {
	FILE *fp;
	fp = fopen("lightdata.txt","r");
	printf("\n\n\t\t\tBill Paid\n");
	printf("      ID\t| current_unit | prev_unit |   prev_bill   |\tcurr_bill\t|\tEND_DATE\t|\t paid\t\n");
	int count = 0;
	lightbill ar[100];
	lightbill list;	
	while(fread(&list,sizeof(list),1,fp)==1){
		if(list.paid_y_n == 'y') {
			ar[count] = list;
			count++;
		}
	}	
	int i;
	for(i = 0; i < count; i++)
        	printf("\n|     %d     |     %d     |     %d     |     %f     |     %f     |     %s     |     %s     |     %c     \n ",ar[i].id,ar[i].curr_unit,ar[i].prev_unit ,ar[i].prev_bill, ar[i].curr_bill, ar[i].end_date, ar[i].month,ar[i].paid_y_n);
	fclose(fp);
}
void show_bill_not_paid() {
	FILE *fp;
	fp = fopen("lightdata.txt","r");
	printf("\n\n\t\t\tBill Not Paid\n");
	printf("      ID\t| current_unit | prev_unit |   prev_bill   |\tcurr_bill\t|\tEND_DATE\t|\t paid\t\n");
	int count = 0;
	lightbill ar[100];
	lightbill list;	
	while(fread(&list,sizeof(list),1,fp)==1){
		if(list.paid_y_n == 'n') {
			ar[count] = list;
			count++;
		}
	}
	int i;	
	for(i = 0; i < count; i++)
        	printf("\n|     %d     |     %d     |     %d     |     %f     |     %f     |     %s     |     %s     |     %c     \n ",ar[i].id,ar[i].curr_unit,ar[i].prev_unit ,ar[i].prev_bill, ar[i].curr_bill, ar[i].end_date, ar[i].month,ar[i].paid_y_n);
	fclose(fp);

}

