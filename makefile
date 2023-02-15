CC = gcc
CXXC = g++
OUTPUT = bin/sbar
WARNINGS = -Wall -Wextra -Wwrite-strings
LINKS = -lX11
CFLAGS = -march=native -O2 -ftree-vectorize -fno-semantic-interposition -fno-plt -pipe -s -flto \
				 $(LINKS) $(WARNINGS) -D_FORTIFY_SOURCE=1
DEBUG = -g

CSRC = $(wildcard src/*.c)
CXXSRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.c, obj/%.o, $(CSRC))
OBJ := $(OBJ) $(patsubst src/%.cpp, obj/%.o, $(CXXSRC))


$(OUTPUT): $(OBJ)
	$(CXXC) $^ -o $@ $(CFLAGS)

obj/%.o: src/%.c
	$(CC) $^ -c -o $@ $(CFLAGS)

obj/%.o: src/%.cpp
	$(CXXC) $^ -c -o $@ $(CFLAGS)

run: $(OUTPUT)
	bin/my_bar


debug: bin/debug
bin/debug: src/*.c
	$(CC) $^ -o $@ $(DEBUG)

clean:
	rm bin/* obj/*

install: $(OUTPUT)
	cp $(OUTPUT) /usr/bin/sbar

uninstall:
	rm -f /usr/bin/sbar

