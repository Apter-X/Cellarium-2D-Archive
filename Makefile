CC=g++

CFLAGS=-c -Wall

DEPENDENCES=-I include -L lib -l SDL2-2.0.0
#DEPENDENCES=-I/include -I/lib

all: game

game:
	$(CC) main.cpp -o luncher $(DEPENDENCES)
clean:
	rm -rf *o luncher
	rm -rf .main.cpp.swp
