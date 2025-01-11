CXX = g++
CXXFLAGS = -Wall -std=c++20
SRC = $(wildcard src/*.cpp)
OBJS = $(SRC:src/%.cpp=bin/%.o)
TARGET = program

all:
	make build
	make run

build: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o bin/$(TARGET)

run:
	bin/$(TARGET)
	
bin/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f bin/*
	touch bin/.gitkeep
