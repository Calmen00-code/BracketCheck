CC = gcc
CFLAGS = -Werror -Wall -pedantic -ansi -g
OBJA = main.o file.o ucp_string.o display.o LinkedList.o newSleep.o stack.o bracket.o
OBJB = main.o file.o ucp_string.o displayStack.o LinkedList.o newSleep.o stack.o bracket.o
EXECA = prog
EXECB = progStack

all : $(EXECA) $(EXECB)

$(EXECA) : $(OBJA)
	$(CC) $(OBJA) -o $(EXECA)

main.o : main.c file.h display.h
	$(CC) $(CFLAGS) -c main.c

file.o : file.c file.h ucp_string.h
	$(CC) $(CFLAGS) -c file.c

ucp_string.o : ucp_string.c ucp_string.h main.h
	$(CC) $(CFLAGS) -c ucp_string.c

display.o : display.c display.h newSleep.h main.h stack.h bracket.h ucp_string.h
	$(CC) $(CFLAGS) -c display.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

newSleep.o : newSleep.c newSleep.h
	$(CC) $(CFLAGS) -c newSleep.c

stack.o : stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

bracket.o : bracket.c main.h bracket.h ucp_string.h
	$(CC) $(CFLAGS) -c bracket.c

$(EXECB) : $(OBJB)
	$(CC) $(OBJB) -o $(EXECB)

displayStack.o : display.c display.h newSleep.h main.h stack.h bracket.h ucp_string.h
	$(CC) $(CFLAGS) -c display.c -o displayStack.o -D STACK 

clean:
	rm -f $(OBJA) $(EXECA) $(OBJB) $(EXECB) 
