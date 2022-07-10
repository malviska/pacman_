C = g++
W = -std=c++11 -Wall

B = ./build
I = ./include
S = ./src
T = ./test

SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: main

main_test:${B}/main_test.o ${B}/map.o ${B}/object.o ${B}/food.o ${B}/pacman.o ${B}/personagem.o ${B}/coordenada.o 
	${C} ${W} ${B}/*.o -o main_test

main: ${B}/main.o ${B}/map.o ${B}/object.o ${B}/food.o ${B}/pacman.o ${B}/personagem.o ${B}/collision.o ${B}/coordenada.o ${B}/ghosts.o ${B}/game.o 
	${C} ${W} ${B}/*.o -o main ${SFML}

${B}/main_test.o: ${T}/main_test.cpp
	${C} ${W} -c ${T}/main_test.cpp -o ${B}/main_test.o
${B}/main.o: main.cpp
	${C} ${W} -c main.cpp -o ${B}/main.o
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

clear:
	rm -f ${B}/*.o