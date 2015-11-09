#include "user.h"
#include "lightbill.h"
#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
void adduser() {
	FILE *fp;
	//creating file if not exist
	fp=fopen("userdata.txt","a");
	fclose(fp);
	// creation of file end
	user obj;
	fflush(stdin);
	printf("\tEnter ID: ");
	scanf("%s", obj.id);	
	fflush(stdin);
	printf("\tEnter Name: ");
	scanf("%s", obj.name);
	printf("\tEnter Age: ");
	scanf("%s", obj.age);
	printf("\tEnter phone_no:");
	scanf("%s", obj.phone_no);
	fflush(stdin);
	printf("\tAddress:");
	scanf("%s", obj.addr);
	printf("\tEmail address:");
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
		printf("Abesent");
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
	printf(" ID\t|	Name\t| Address\t|Age \t |\tphoneno \t|\t Email ID\t|\n");
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
        	printf("\n|%s| %s| %s\t| %s| %s| %s\n",ar[i].id,ar[i].name,ar[i].addr ,ar[i].id, ar[i].phone_no, ar[i].email);
	gui(count, 6, ar, argc, argv);
}
void gui(int count, int cols, user ar[], int argc, char *argv[]) {
	GtkWidget *window;
  GtkWidget *table;
  GtkWidget *button;



  gtk_init(&argc, &argv);
 window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request (GTK_WIDGET (window), 200, 200);
    gtk_window_set_title (GTK_WINDOW (window), "GTK Entry");
    g_signal_connect (window, "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect_swapped (window, "delete-event",
                              G_CALLBACK (gtk_widget_destroy), 
                              window);
  table = gtk_table_new(4, 4, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 0);
  gtk_table_set_col_spacings(GTK_TABLE(table), 0);

  int i = 0;
  int j = 0;
  int pos = 0;
  for (i = 0; i <= count; i++) {
	j = 0;
	if(i == 0) {
	button = gtk_label_new ("ID");
	gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);j++;
	button = gtk_label_new ("Name");
	gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);j++;
	button = gtk_label_new ("Address");
	gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);j++;
	button = gtk_label_new ("phone_no");
	gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);j++;
	button = gtk_label_new ("Age");
	gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);j++;
	button = gtk_label_new ("Email");
	gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);
	}
else{      button = gtk_label_new (ar[i-1].id);
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);j++;
      button = gtk_label_new (ar[i-1].name);
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);j++;
      button = gtk_label_new (ar[i-1].addr);
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);j++;
      button = gtk_label_new (ar[i-1].phone_no);
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);j++;
      button = gtk_label_new (ar[i-1].age);
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);j++;
      button = gtk_label_new (ar[i-1].email);
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);
}
}
  gtk_container_add(GTK_CONTAINER(window), table);

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);

  gtk_main();


}
