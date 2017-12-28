prog1: prog1.o hashtable.o heap.o entry.o
	g++ prog1.o hashtable.o heap.o entry.o -o prog1

prog1.o: prog1.cpp
	g++ -c -g prog1.cpp

hashtable.o: hashtable.cpp
	g++ -c -g hashtable.cpp

heap.o: heap.cpp
	g++ -c -g heap.cpp

entry.o: entry.cpp
	g++ -c -g entry.cpp

clean:
	rm -f *.o prog1
