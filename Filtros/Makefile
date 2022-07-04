cflags=-g -std=c++17
cc=g++

bin/filtro: build/Imagen.o build/main.o src/aprueba.s
	g++ -o bin/filtro build/Imagen.o build/main.o src/aprueba.s $(cflags)

build/Imagen.o: src/Imagen.cpp
	$(cc) -c -o build/Imagen.o src/Imagen.cpp $(cflags)

build/main.o: src/main.cpp
	$(cc) -c -o build/main.o src/main.cpp $(cflags)

clean:
	rm -r build/* bin/*
