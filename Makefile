CC=g++
CFLAGS= -Wall -g

TARGET= ./bin/tp2.out
OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

all: ${TARGET}

${TARGET}: ${OBJ_DIR}/Vertice.o ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} ${OBJ_DIR}/*.o -o ${TARGET}

${OBJ_DIR}/Vertice.o: ${INCLUDE_DIR}/Vertice.hpp ${SRC_DIR}/Vertice.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Vertice.cpp -o ${OBJ_DIR}/Vertice.o

${OBJ_DIR}/main.o: ${INCLUDE_DIR}/Vertice.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

run: all
	${TARGET} ./tp2.out

clean:
	rm -f ${OBJ_DIR}/* ${TARGET}