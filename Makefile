CC = g++
CFLAGS = -Wall -pedantic -g

output: RubberMain.o RubberArray.o
	$(CC) $(CFLAGS) RubberMain.o RubberArray.o -o output

main.out: RubberMain.cpp
	$(CC) $(CFLAGS) RubberMain.cpp

RubberArray.o: RubberArray.h

clean:
	rm *.o
