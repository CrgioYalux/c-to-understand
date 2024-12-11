CC = cc
CFLAGS = -Wall -g -Wextra
OBJECTS = build/main.o build/ring.o
HEADERS = src/ring.h

.PHONY: all clean run build

all: build build/charspinner

build:
	mkdir -p build

build/charspinner: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

build/main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

build/ring.o: src/ring.c src/ring.h
	$(CC) $(CFLAGS) -o $@ -c $<

run:
	clear
	make
	./charspinner

clean:
	rm -rf build charspinner $(OBJECTS) 
