CC = g++
CFLAGS=-std=c++11 -g -w -Wall
SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
TARGET= pacman.o
TARGET2= test.o

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
TESTS_DIR = ./tests
BUILD_TESTS_DIR = ./build_tests

# ${TARGET}: ${BUILD_DIR}/*.o
# 	${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o ${SFMLFLAGS}
testCellMaker: ${BUILD_DIR}/pacman.o ${BUILD_TESTS_DIR}/cell_maker.test.o 
	${CC} ${CFLAGS} -o ${BUILD_TESTS_DIR}/testCellMaker.o ${BUILD_DIR}/cell_maker.o ${BUILD_DIR}/pacman.o ${BUILD_TESTS_DIR}/cell_maker.test.o 

testMapa: ${BUILD_DIR}/pacman.o ${BUILD_DIR}/cell_maker.o ${BUILD_DIR}/mapa.o ${BUILD_TESTS_DIR}/mapa.test.o
	${CC} ${CFLAGS} -o ${BUILD_TESTS_DIR}/testMapa.o  ${BUILD_DIR}/cell_maker.o ${BUILD_DIR}/pacman.o ${BUILD_DIR}/mapa.o ${BUILD_TESTS_DIR}/mapa.test.o ${SFMLFLAGS}

${BUILD_TESTS_DIR}/mapa.test.o: ${BUILD_DIR}/mapa.o ${BUILD_DIR}/pacman.o ${BUILD_DIR}/cell_maker.o 
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${TESTS_DIR}/mapa.test.cpp -o ${BUILD_TESTS_DIR}/mapa.test.o ${SFMLFLAGS}

${BUILD_TESTS_DIR}/cell_maker.test.o: ${BUILD_DIR}/cell_maker.o ${BUILD_DIR}/pacman.o
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${TESTS_DIR}/cell_maker.test.cpp -o ${BUILD_TESTS_DIR}/cell_maker.test.o 

${BUILD_DIR}/cell_maker.o: ${INCLUDE_DIR}/cell_maker.hpp ${SRC_DIR}/cell_maker.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/cell_maker.cpp -o ${BUILD_DIR}/cell_maker.o

${BUILD_DIR}/pacman.o: ${INCLUDE_DIR}/pacman.hpp ${SRC_DIR}/pacman.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/pacman.cpp -o ${BUILD_DIR}/pacman.o 

${BUILD_DIR}/mapa.o: ${INCLUDE_DIR}/mapa.hpp ${SRC_DIR}/mapa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/mapa.cpp -o ${BUILD_DIR}/mapa.o ${SFMLFLAGS}


# Rule for cleaning files generated during compilation. 
# Call 'make clean' to use it
clean:
	rm -f ${BUILD_DIR}/* ${BUILD_TESTS_DIR}/*

