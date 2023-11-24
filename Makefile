CC = g++	# use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++17	# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.

all: graph
SRCS = Vertex.cpp Graph.cpp Main.cpp
DEPS = $(SRCS:.cpp=.d)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

graph: Main.o Graph.o Vertex.o
	$(CC) Main.o Graph.o Vertex.o -o graph
	
clean:
	rm *.o graph
