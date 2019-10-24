#Nome do executável
exName = bin/BST

# Arquivos .o
o_archives = build/Menu.o build/Node.o build/Controlador.o

# Compilador
cc = g++

# flags
cc_flags = -Wall -std=c++11 -I include

text = "Como executar: <make BST> ou <./bin/BST>"

all: $(exName)
	@echo $(text)

$(exName): $(o_archives) build/main.o
	$(cc) $(cc_flags) $(o_archives) build/main.o -o $(exName)

build/main.o: src/main.cpp
	$(cc) $(cc_flags) -c src/main.cpp && mv main.o build

build/Menu.o: src/Menu.cpp
	$(cc) $(cc_flags) -c src/Menu.cpp && mv Menu.o build

build/Node.o: src/Node.cpp
	$(cc) $(cc_flags) -c src/Node.cpp && mv Node.o build

build/Controlador.o: src/Controlador.cpp
	$(cc) $(cc_flags) -c src/Controlador.cpp && mv Controlador.o build

clear:
	rm -rf build/*.o