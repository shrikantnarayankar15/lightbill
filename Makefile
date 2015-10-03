try: main.o db.o user.o
	cc main.o db.o user.o -o try
main.o: main.c 
	cc -Wall -c main.c
db.o: db.c db.h
	cc -Wall -c db.c
user.o: user.c db.h
	cc -Wall -c user.c
