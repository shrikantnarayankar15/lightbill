#include <mysql.h>
#include <stdio.h>
typedef struct db {
	MYSQL *con;
	MYSQL_RES *res;
}db;
void init(db *a);
void selectdb(db *a);
void result(db *a, char *query);

