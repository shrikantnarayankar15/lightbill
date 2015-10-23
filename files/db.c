#include "db.h"
void init(db *a){
	a->con = mysql_init(NULL);
}
void selectdb(db *a){
	if(mysql_real_connect(a->con, "localhost", "root", "shrikant", "data", 0,0,0)){
	}
}
void result(db *a, char *query){
	mysql_query(a->con, query);
	a->res = mysql_store_result(a->con);
}
