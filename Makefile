all: Column.o main.o Wrapper.o
	g++ Column.o main.o Wrapper.o -o prog

Column.o: Column.cpp Column.hpp
	g++ -c Column.cpp

Wrapper.o: Wrapper.cpp Wrapper.hpp
	g++ -c Wrapper.cpp

run: 
	./prog

clean:
	rm *.o prog

