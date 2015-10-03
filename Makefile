try: main.o db.o user.o 
	cc main.o db.o user.o -o try  `mysql_config --cflags --libs`
main.o: main.c
	cc -Wall -c main.c `mysql_config --cflags --libs`
db.o: db.c db.h
	cc -Wall -c db.c  `mysql_config --cflags --libs`
user.o: user.c db.h
	cc -Wall -c user.c  `mysql_config --cflags --libs`
