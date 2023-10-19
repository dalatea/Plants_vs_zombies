set(CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 3.27)

project(Project)

set(CMAKE_CXX_STANDARD 17)	

include_directories(include)

add_executable(
	Project
	src/escape.cpp
	src/graphics.cpp
	src/field.cpp
	src/keyboard.cpp
	src/objects.cpp
	src/rules.cpp
	src/game.cpp
	src/user.cpp
	src/zombie.cpp
	src/main.cpp
	src/plants.cpp
	src/bullet.cpp
)


