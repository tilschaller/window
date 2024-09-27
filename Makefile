#needed libs: glfw3, glm

CC = g++

SRC = main.cpp glad/src/glad.c stb_image.h src/camera.cpp src/shader.cpp

all:
	${CC} ${SRC} -o window -lglfw -lglm
