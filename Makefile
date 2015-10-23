all: server client admin
server: server.o db.o 
	cc server.o db.o -o server  `mysql_config --cflags --libs` 
client: client.o 
	cc client.o -o client  `mysql_config --cflags --libs` 
admin: admin.o db.o
	cc admin.o db.o -o admin  `mysql_config --cflags --libs` 
db.o: db.c db.h
	cc -c db.c `mysql_config --cflags --libs`
admin.o: admin.c user.h db.h
	cc -c admin.c `mysql_config --cflags --libs` -Wall
server.o: server.c user.h db.h
	cc -c server.c `mysql_config --cflags --libs` 
client.o: client.c user.h 
	cc -c client.c `mysql_config --cflags --libs`

