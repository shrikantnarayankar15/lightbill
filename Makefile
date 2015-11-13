all: admin server client
client: client.o 
	cc client.o -o client
server: server.o lightbill.o user.o
	cc server.o lightbill.o user.o -o server  
admin: user.o admin.o lightbill.o 
	cc user.o admin.o lightbill.o -o admin  
admin.o: admin.c user.h lightbill.h
	cc -c admin.c 
user.o: user.c lightbill.c user.h lightbill.h
	cc -c user.c lightbill.c  
lightbill.o: lightbill.c lightbill.h 
	cc -c lightbill.c 
server.o: server.c lightbill.h user.h
	cc -c server.c
client.o: client.c lightbill.h user.h client.h
	cc -c client.c  
	

