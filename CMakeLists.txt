set(CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 3.27)

project(Plants_VS_Zombies)

set(CMAKE_CXX_STANDARD 17)	

include_directories(include)

add_executable(
	Plants_VS_Zombies
	src/settings.cpp
	src/escape.cpp
	src/graphics.cpp
	src/keyboard.cpp
	src/field_model.cpp
	src/field_view.cpp
	src/control.cpp
	src/rules.cpp
	src/objects.cpp
	src/main.cpp
)

