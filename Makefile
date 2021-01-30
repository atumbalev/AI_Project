BIN=puzzle
SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)


run:
	make build
	./$(BIN)

build: $(OBJ)
	g++ -o $(BIN) $^

clean:
	rm -f *.o
	rm -f $(BIN)