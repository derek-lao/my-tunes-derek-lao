all: library.o song_node.o main.o
	gcc -o myTunesTest.exe main.o song_node.o library.o

library.o: library.c library.h song_node.h
	gcc -c library.c

song_node.o: song_node.c song_node.h
	gcc -c song_node.c

main.o: main.c song_node.h library.h
	gcc -c main.c

run:
	./myTunesTest.exe

clean:
	rm *.o
	rm *~
