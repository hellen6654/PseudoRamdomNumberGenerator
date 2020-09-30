.PHONY: dirs clean

all: dirs main

main: src/main.cpp src/PseudoRamdomNumber.h 
	g++ src/main.cpp -o bin/main

dirs:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/*