CC = gcc
CFLAGS =  -pipe  -O -W -Wall -Wpointer-arith -Wno-unused-parameter -Wunused-function -Wunused-variable -Wunused-value -Werror -g
LIBS = 
LINK = $(CC)

DEPS = sb.h event.h request.h response.h
INCS = 

default: sb

sb: sb.o event.o request.o response.o
	$(LINK) -o sb sb.o event.o request.o response.o $(LIBS)

sb.o: $(DEPS) sb.c
	$(CC) -c $(CFLAGS) $(INCS) -o sb.o sb.c

event.o: $(DEPS) event.c
	$(CC) -c $(CFLAGS) $(INCS) -o event.o event.c

request.o: $(DEPS) request.c
	$(CC) -c $(CFLAGS) $(INCS) -o request.o request.c

response.o: $(DEPS) response.c
	$(CC) -c $(CFLAGS) $(INCS) -o response.o response.c

clean: 
	rm -f *.o
	rm -f sb

