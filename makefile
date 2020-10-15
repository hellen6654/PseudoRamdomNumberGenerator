.PHONY: dirs clean hw1 hw2

all: dirs hw2

main: src/main.cpp src/PseudoRamdomNumber.h 
	g++ src/main.cpp -o bin/main

hw1: src/main.cpp src/PseudoRamdomNumber.h src/hw1/first.cpp src/hw1/second.cpp src/hw1/third.cpp src/hw1/fourth.cpp
	g++ src/main.cpp -o bin/main

hw2: src/main.cpp src/PseudoRamdomNumber.h src/hw2/first.cpp #src/hw2/second.cpp src/hw2/third.cpp src/hw2/fourth.cpp
	g++ src/main.cpp -o bin/main

dirs:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/*