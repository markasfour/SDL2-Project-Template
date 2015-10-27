all:
	if [ ! -d "./bin" ];\
		then mkdir bin;\
	fi
	g++ -std=c++11 src/main.cpp -lSDL2 -lSDL2_image -o bin/a.out

clean:
	rm -rf bin
