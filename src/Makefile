## Makefile for Bloom Filter test
## nmt 2018

CC = g++

all:	prim.o graph.o prim_test

prim.o: prim.cpp
	$(CC) $(CFLAGS) -c prim.cpp

graph.o: graph.cpp
	$(CC) $(CFLAGS) -c graph.cpp

prim_test: prim.o prim.h prim_cfg.h graph.o graph.h graph_cfg.h
	$(CC) $(CFLAGS) -o prim_test prim.o graph.o main.cpp

clean:
	rm *.o prim_test
