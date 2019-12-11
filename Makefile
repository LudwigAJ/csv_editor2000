TARGET=bin/main

OBJECTS=bin/Column.o bin/Wrapper.o $(TARGET).o

bin/%.o : src/%.cpp
	g++ -Wall -std=c++11 -I ./inc  -c $< -o $@

all: $(TARGET)
	

$(TARGET): $(OBJECTS)
	g++ $(OBJECTS) -std=c++11 -o $(TARGET)

run: 
	./$(TARGET)

clean:
	rm bin/*.o $(TARGET)

