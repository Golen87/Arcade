#files := src/main.cpp src/game.cpp src/game.h src/state.cpp src/state.h src/states/testState.cpp src/states/testState.h src/resourceManager.h src/resourceManager.cpp src/animation.h
files := $(wildcard src/*.cpp) $(wildcard src/objects/*.cpp) $(wildcard src/states/*.cpp)
#files := $(shell find src -n "*.cpp")

objects := $(patsubst %.cpp, %.o, $(files))

all: executable

executable: $(objects)
	g++ $(objects) -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp
	clear
	g++ -c $< -o $@ 

clean:
	rm *.o

cleanall: clean
	rm executable
