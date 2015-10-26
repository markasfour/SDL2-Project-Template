all:
	if [ ! -d "./bin" ];\
		then mkdir bin;\
	fi
	g++ -std=c++11 src/main.cpp -lSDL2 -o bin/a.out

clean:
	rm -rf bin
