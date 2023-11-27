set(CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 3.27)

project(Project)

set(CMAKE_CXX_STANDARD 17)	

include_directories(include)

add_executable(
	Project
	src/settings.cpp
	src/escape.cpp
	src/graphics.cpp
	src/keyboard.cpp
	src/field_model.cpp
	src/field_view.cpp
	src/control.cpp
)

