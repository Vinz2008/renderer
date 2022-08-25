all: setup build/renderer.o build/canva.o linking cleanbuild

setup:
	rm -rf build
	mkdir build

build/renderer.o:
	gcc -c -g -o build/renderer.o main.c -Wall

build/canva.o:
	gcc -c -g -o build/canva.o libs/canva.c -Wall

cleanbuild:
	rm -rf build


linking:
	gcc -o renderer build/renderer.o build/canva.o -lSDL2 -lm

run:
	./renderer