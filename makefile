all:
g++ main.cpp -g -o ./bin/run
./bin/run
compile:
g++ main.cpp -g -o ./bin/run
run:
./bin/run
test pacman:
g++ pacman.test.cpp -g -o ./bin/run