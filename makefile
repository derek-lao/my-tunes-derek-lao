all: functions.o main.o
	gcc -o myTunesTest.exe main.o functions.o

functions.o: functions.c song_node.h
	gcc -c functions.c

main.o: main.c song_node.h
	gcc -c main.c

run:
	./myTunesTest.exe

clean:
	rm *.o
	rm *~
