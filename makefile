all: main
main: main.o Ball.o Paddle.o
	g++ main.o Ball.o Paddle.o -o main -lglfw -lGL
main.o: main.cpp
	g++ -c main.cpp
Ball.o: Ball.cpp Ball.h
	g++ -c Ball.cpp
Paddle.o: Paddle.cpp Paddle.h
	g++ -c Paddle.cpp
