C = g++
W = -std=c++11 -Wall -ggdb3
COVERAGE_FLAG = --coverage


B = ./build
BT = ./build_tests
I = ./include
S = ./src
T = ./test

SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: program

collision_test: ${BT}/map_test.o ${BT}/object_test.o ${BT}/pacman_test.o ${BT}/food_test.o ${BT}/personagem_test.o ${BT}/collision_test.o ${BT}/coordenada_test.o ${BT}/ghosts_test.o ${BT}/game_test.o 
	${C} ${W} ${COVERAGE_FLAG} -o ${BT}/collision_test ${T}/collision_test.cpp ${BT}/*.o ${SFML}

main: ${B}/main.o ${B}/menu.o ${B}/map.o ${B}/object.o ${B}/food.o ${B}/pacman.o ${B}/personagem.o ${B}/collision.o ${B}/coordenada.o ${B}/ghosts.o ${B}/game.o 
	${C} ${W} ${B}/*.o -o main ${SFML}

run_tests:
	${BT}/collision_test

${B}/main_test.o: ${T}/main_test.cpp
	${C} ${W} ${COVERAGE_FLAG} -c ${T}/main_test.cpp -o ${B}/main_test.o
	
${B}/main.o: main.cpp
	${C} ${W} -c main.cpp -o ${B}/main.o
${B}/menu.o: ${I}/menu.hpp ${S}/menu.cpp
	${C} ${W} -c ${S}/menu.cpp -o ${B}/menu.o
${B}/coordenada.o: ${I}/coordenada.hpp ${S}/coordenada.cpp
	${C} ${W} -c ${S}/coordenada.cpp -o ${B}/coordenada.o
${B}/food.o: ${I}/food.hpp ${S}/food.cpp
	${C} ${W} -c ${S}/food.cpp -o ${B}/food.o
${B}/map.o: ${I}/map.hpp ${S}/map.cpp
	${C} ${W} -c ${S}/map.cpp -o ${B}/map.o
${B}/object.o: ${I}/object.hpp ${S}/object.cpp
	${C} ${W} -c ${S}/object.cpp -o ${B}/object.o
${B}/pacman.o: ${I}/pacman.hpp ${S}/pacman.cpp
	${C} ${W} -c ${S}/pacman.cpp -o ${B}/pacman.o
${B}/personagem.o: ${I}/personagem.hpp ${S}/personagem.cpp
	${C} ${W} -c ${S}/personagem.cpp -o ${B}/personagem.o
${B}/game.o: ${B}/collision.o ${I}/game.hpp ${S}/game.cpp
	${C} ${W} -c ${S}/game.cpp -o ${B}/game.o
${B}/ghosts.o: ${I}/ghosts.hpp ${S}/ghosts.cpp
	${C} ${W} -I ${I} -c ${S}/ghosts.cpp -o ${B}/ghosts.o
${B}/collision.o: ${I}/collision.hpp ${S}/collision.cpp
	${C} ${W} -I ${I} -c ${S}/collision.cpp -o ${B}/collision.o

${BT}/main_test.o: main.cpp
	${C} ${W} ${COVERAGE_FLAG} -c main.cpp -o ${BT}/main.o
${BT}/menu_test.o: ${I}/menu.hpp ${S}/menu.cpp
	${C} ${W} ${COVERAGE_FLAG} -c ${S}/menu.cpp -o ${BT}/menu.o
${BT}/coordenada_test.o: ${I}/coordenada.hpp ${S}/coordenada.cpp
	${C} ${W} ${COVERAGE_FLAG} -c ${S}/coordenada.cpp -o ${BT}/coordenada.o
${BT}/food_test.o: ${I}/food.hpp ${S}/food.cpp
	${C} ${W} ${COVERAGE_FLAG} -c ${S}/food.cpp -o ${BT}/food.o
${BT}/map_test.o: ${I}/map.hpp ${S}/map.cpp
	${C} ${W} ${COVERAGE_FLAG} -c ${S}/map.cpp -o ${BT}/map.o
${BT}/object_test.o: ${I}/object.hpp ${S}/object.cpp
	${C} ${W} ${COVERAGE_FLAG} -c ${S}/object.cpp -o ${BT}/object.o
${BT}/pacman_test.o: ${I}/pacman.hpp ${S}/pacman.cpp
	${C} ${W} ${COVERAGE_FLAG} -c ${S}/pacman.cpp -o ${BT}/pacman.o
${BT}/personagem_test.o: ${I}/personagem.hpp ${S}/personagem.cpp
	${C} ${W} ${COVERAGE_FLAG} -c ${S}/personagem.cpp -o ${BT}/personagem.o
${BT}/game_test.o: ${BT}/collision.o ${I}/game.hpp ${S}/game.cpp
	${C} ${W} ${COVERAGE_FLAG} -c ${S}/game.cpp -o ${BT}/game.o
${BT}/ghosts_test.o: ${I}/ghosts.hpp ${S}/ghosts.cpp
	${C} ${W} ${COVERAGE_FLAG} -I ${I} -c ${S}/ghosts.cpp -o ${BT}/ghosts.o
${BT}/collision_test.o: ${I}/collision.hpp ${S}/collision.cpp
	${C} ${W} ${COVERAGE_FLAG} -I ${I} -c ${S}/collision.cpp -o ${BT}/collision.o

clear:
	rm -f ./*.o
	rm -f ./*.gcda
	rm -f ./*.gcno
	rm -f ${B}/*.o
	rm -f ${B}/*.gcda
	rm -f ${B}/*.gcno
	rm -f ${BT}/*.o
	rm -f ${BT}/*.gcda
	rm -f ${BT}/*.gcno