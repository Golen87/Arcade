files := src/main.cpp

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
