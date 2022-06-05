all: setup build/renderer.o build/writeToCanva.o linking cleanbuild

setup:
	rm -rf build
	mkdir build

build/renderer.o:
	gcc -c -g -o build/renderer.o main.c

build/writeToCanva.o:
	gcc -c -g -o build/writeToCanva.o libs/writeToCanva.c

cleanbuild:
	rm -rf build


linking:
	gcc -o renderer build/renderer.o build/writeToCanva.o -lSDL2



run:
	./renderer