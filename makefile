C = g++
W = -std=c++11 -Wall

E = ./exec
I = ./include
S = ./src

SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: main

main: ${E}/main.o ${E}/map.o ${E}/object.o ${E}/food.o ${E}/pacman.o ${E}/personagem.o ${E}/coordenada.o ${E}/game.o
	${C} ${W} ${E}/*.o -o main ${SFML}
${E}/main.o: main.cpp
	${C} ${W} -c main.cpp -o ${E}/main.o
${E}/coordenada.o: ${I}/coordenada.hpp ${S}/coordenada.cpp
	${C} ${W} -c ${S}/coordenada.cpp -o ${E}/coordenada.o
${E}/food.o: ${I}/food.hpp ${S}/food.cpp
	${C} ${W} -c ${S}/food.cpp -o ${E}/food.o
${E}/map.o: ${I}/map.hpp ${S}/map.cpp
	${C} ${W} -c ${S}/map.cpp -o ${E}/map.o
${E}/object.o: ${I}/object.hpp ${S}/object.cpp
	${C} ${W} -c ${S}/object.cpp -o ${E}/object.o
${E}/pacman.o: ${I}/pacman.hpp ${S}/pacman.cpp
	${C} ${W} -c ${S}/pacman.cpp -o ${E}/pacman.o
${E}/personagem.o: ${I}/personagem.hpp ${S}/personagem.cpp
	${C} ${W} -c ${S}/personagem.cpp -o ${E}/personagem.o
${E}/game.o: ${I}/game.hpp ${S}/game.cpp
	${C} ${W} -c ${S}/game.cpp -o ${E}/game.o