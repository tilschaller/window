#needed libs: glfw3, glm

CC = g++

SRC = main.cpp glad/src/glad.c src/camera.cpp

all:
	${CC} ${SRC} -o window -lglfw -lglm
