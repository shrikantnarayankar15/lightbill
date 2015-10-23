#include <mysql.h>
#include <stdio.h>
typedef struct db {
	MYSQL *con;
	MYSQL_RES *res;
}db;
void closedb(db *a);
void init(db *a);
void selectdb(db *a);
void result(db *a, char *query);

