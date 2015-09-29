#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct db {
	MYSQL *con;
	MYSQL_RES *res;
}db;
void init(db *a);
void selectdb(db *a);
void result(db *a, char *query);
void lightbilldisplay();
