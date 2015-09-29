#include "db.h"
#include <stdio.h>
void init(db *a) {
	a->con = mysql_init(NULL);
}

void selectdb(db *a) {
	mysql_real_connect(a->con, "localhost", "root", "shrikant", "data", 0, NULL, 0);
}

void result(db *a, char *query) {
	mysql_query(a->con, query);
	a->res = mysql_store_result(a->con);
}
