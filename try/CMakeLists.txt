set(CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 3.27)

project(Project)

set(CMAKE_CXX_STANDARD 17)	

include_directories(include)

add_executable(
	Project
	settings.cpp
	escape.cpp
	graphics.cpp
	keyboard.cpp
	field_model.cpp
	field_view.cpp
)


