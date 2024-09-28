#needed libs: glfw3, glm

CC = g++

SRC = main.cpp deps/glad/src/glad.c deps/stb_image/stb_image.c src/camera.cpp src/shader.cpp src/terrain.cpp

all:
	${CC} ${SRC} -o window -lglfw -lglm
