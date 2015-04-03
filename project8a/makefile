all: fcd

fcd: fcd.cpp class.o
	g++ fcd.cpp class.o -o fcd

class.o: class.cpp
	g++ -c class.cpp -o class.o



clean:
	rm  *.o fcd
