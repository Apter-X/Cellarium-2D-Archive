CC=gcc

CFLAGS=-c -Wall

DEPENDENCES=-I include -L lib -l SDL2-2.0.0

all: luncher

luncher: compile 
	./luncher

compile: clean
	$(CC) main.c -o luncher $(DEPENDENCES)
clean:
	rm -rf *o luncher
	rm -rf .main.cpp.swp