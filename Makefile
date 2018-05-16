# Compiler
CC = g++

INC = ./include
SRC = ./src
OBJ = ./build
BIN = ./bin

CPPFLAGS = -O0 -Wall -pedantic -std=c++11 -I$(INC)
OBJECTS = $(OBJ)/movimentacao.o $(OBJ)/conta.o $(OBJ)/corrente.o $(OBJ)/poupanca.o $(OBJ)/banco.o $(OBJ)/main.o

PROG = $(BIN)/banco

all: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJECTS)

$(OBJ)/movimentacao.o: $(INC)/movimentacao.h
	$(CC) $(CPPFLAGS) -c $(SRC)/movimentacao.cpp -o $@

$(OBJ)/conta.o: $(INC)/conta.h
	$(CC) $(CPPFLAGS) -c $(SRC)/conta.cpp -o $@

$(OBJ)/corrente.o: $(INC)/corrente.h $(OBJ)/conta.o
	$(CC) $(CPPFLAGS) -c $(SRC)/corrente.cpp -o $@

$(OBJ)/poupanca.o: $(INC)/poupanca.h $(OBJ)/conta.o
	$(CC) $(CPPFLAGS) -c $(SRC)/poupanca.cpp -o $@

$(OBJ)/banco.o: $(INC)/banco.h $(OBJ)/movimentacao.o $(OBJ)/conta.o $(OBJ)/corrente.o $(OBJ)/poupanca.o
	$(CC) $(CPPFLAGS) -c $(SRC)/banco.cpp -o $@

$(OBJ)/main.o: $(OBJ)/movimentacao.o $(OBJ)/conta.o $(OBJ)/corrente.o $(OBJ)/poupanca.o $(OBJ)/banco.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

clean:
	rm -f $(PROG) $(OBJECTS)
