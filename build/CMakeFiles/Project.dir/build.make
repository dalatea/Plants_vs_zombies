# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1345/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1345/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dilyara/Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dilyara/Project/build

# Include any dependencies generated for this target.
include CMakeFiles/Project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project.dir/flags.make

CMakeFiles/Project.dir/src/settings.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/settings.cpp.o: /home/dilyara/Project/src/settings.cpp
CMakeFiles/Project.dir/src/settings.cpp.o: CMakeFiles/Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dilyara/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project.dir/src/settings.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project.dir/src/settings.cpp.o -MF CMakeFiles/Project.dir/src/settings.cpp.o.d -o CMakeFiles/Project.dir/src/settings.cpp.o -c /home/dilyara/Project/src/settings.cpp

CMakeFiles/Project.dir/src/settings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/settings.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dilyara/Project/src/settings.cpp > CMakeFiles/Project.dir/src/settings.cpp.i

CMakeFiles/Project.dir/src/settings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/settings.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dilyara/Project/src/settings.cpp -o CMakeFiles/Project.dir/src/settings.cpp.s

CMakeFiles/Project.dir/src/escape.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/escape.cpp.o: /home/dilyara/Project/src/escape.cpp
CMakeFiles/Project.dir/src/escape.cpp.o: CMakeFiles/Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dilyara/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project.dir/src/escape.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project.dir/src/escape.cpp.o -MF CMakeFiles/Project.dir/src/escape.cpp.o.d -o CMakeFiles/Project.dir/src/escape.cpp.o -c /home/dilyara/Project/src/escape.cpp

CMakeFiles/Project.dir/src/escape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/escape.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dilyara/Project/src/escape.cpp > CMakeFiles/Project.dir/src/escape.cpp.i

CMakeFiles/Project.dir/src/escape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/escape.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dilyara/Project/src/escape.cpp -o CMakeFiles/Project.dir/src/escape.cpp.s

CMakeFiles/Project.dir/src/graphics.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/graphics.cpp.o: /home/dilyara/Project/src/graphics.cpp
CMakeFiles/Project.dir/src/graphics.cpp.o: CMakeFiles/Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dilyara/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project.dir/src/graphics.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project.dir/src/graphics.cpp.o -MF CMakeFiles/Project.dir/src/graphics.cpp.o.d -o CMakeFiles/Project.dir/src/graphics.cpp.o -c /home/dilyara/Project/src/graphics.cpp

CMakeFiles/Project.dir/src/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/graphics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dilyara/Project/src/graphics.cpp > CMakeFiles/Project.dir/src/graphics.cpp.i

CMakeFiles/Project.dir/src/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/graphics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dilyara/Project/src/graphics.cpp -o CMakeFiles/Project.dir/src/graphics.cpp.s

CMakeFiles/Project.dir/src/keyboard.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/keyboard.cpp.o: /home/dilyara/Project/src/keyboard.cpp
CMakeFiles/Project.dir/src/keyboard.cpp.o: CMakeFiles/Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dilyara/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project.dir/src/keyboard.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project.dir/src/keyboard.cpp.o -MF CMakeFiles/Project.dir/src/keyboard.cpp.o.d -o CMakeFiles/Project.dir/src/keyboard.cpp.o -c /home/dilyara/Project/src/keyboard.cpp

CMakeFiles/Project.dir/src/keyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/keyboard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dilyara/Project/src/keyboard.cpp > CMakeFiles/Project.dir/src/keyboard.cpp.i

CMakeFiles/Project.dir/src/keyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/keyboard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dilyara/Project/src/keyboard.cpp -o CMakeFiles/Project.dir/src/keyboard.cpp.s

CMakeFiles/Project.dir/src/field_model.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/field_model.cpp.o: /home/dilyara/Project/src/field_model.cpp
CMakeFiles/Project.dir/src/field_model.cpp.o: CMakeFiles/Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dilyara/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Project.dir/src/field_model.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project.dir/src/field_model.cpp.o -MF CMakeFiles/Project.dir/src/field_model.cpp.o.d -o CMakeFiles/Project.dir/src/field_model.cpp.o -c /home/dilyara/Project/src/field_model.cpp

CMakeFiles/Project.dir/src/field_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/field_model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dilyara/Project/src/field_model.cpp > CMakeFiles/Project.dir/src/field_model.cpp.i

CMakeFiles/Project.dir/src/field_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/field_model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dilyara/Project/src/field_model.cpp -o CMakeFiles/Project.dir/src/field_model.cpp.s

CMakeFiles/Project.dir/src/field_view.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/field_view.cpp.o: /home/dilyara/Project/src/field_view.cpp
CMakeFiles/Project.dir/src/field_view.cpp.o: CMakeFiles/Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dilyara/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Project.dir/src/field_view.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project.dir/src/field_view.cpp.o -MF CMakeFiles/Project.dir/src/field_view.cpp.o.d -o CMakeFiles/Project.dir/src/field_view.cpp.o -c /home/dilyara/Project/src/field_view.cpp

CMakeFiles/Project.dir/src/field_view.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/field_view.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dilyara/Project/src/field_view.cpp > CMakeFiles/Project.dir/src/field_view.cpp.i

CMakeFiles/Project.dir/src/field_view.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/field_view.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dilyara/Project/src/field_view.cpp -o CMakeFiles/Project.dir/src/field_view.cpp.s

CMakeFiles/Project.dir/src/control.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/control.cpp.o: /home/dilyara/Project/src/control.cpp
CMakeFiles/Project.dir/src/control.cpp.o: CMakeFiles/Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/dilyara/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Project.dir/src/control.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project.dir/src/control.cpp.o -MF CMakeFiles/Project.dir/src/control.cpp.o.d -o CMakeFiles/Project.dir/src/control.cpp.o -c /home/dilyara/Project/src/control.cpp

CMakeFiles/Project.dir/src/control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/control.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dilyara/Project/src/control.cpp > CMakeFiles/Project.dir/src/control.cpp.i

CMakeFiles/Project.dir/src/control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/control.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dilyara/Project/src/control.cpp -o CMakeFiles/Project.dir/src/control.cpp.s

# Object files for target Project
Project_OBJECTS = \
"CMakeFiles/Project.dir/src/settings.cpp.o" \
"CMakeFiles/Project.dir/src/escape.cpp.o" \
"CMakeFiles/Project.dir/src/graphics.cpp.o" \
"CMakeFiles/Project.dir/src/keyboard.cpp.o" \
"CMakeFiles/Project.dir/src/field_model.cpp.o" \
"CMakeFiles/Project.dir/src/field_view.cpp.o" \
"CMakeFiles/Project.dir/src/control.cpp.o"

# External object files for target Project
Project_EXTERNAL_OBJECTS =

Project: CMakeFiles/Project.dir/src/settings.cpp.o
Project: CMakeFiles/Project.dir/src/escape.cpp.o
Project: CMakeFiles/Project.dir/src/graphics.cpp.o
Project: CMakeFiles/Project.dir/src/keyboard.cpp.o
Project: CMakeFiles/Project.dir/src/field_model.cpp.o
Project: CMakeFiles/Project.dir/src/field_view.cpp.o
Project: CMakeFiles/Project.dir/src/control.cpp.o
Project: CMakeFiles/Project.dir/build.make
Project: CMakeFiles/Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/dilyara/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project.dir/build: Project
.PHONY : CMakeFiles/Project.dir/build

CMakeFiles/Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project.dir/clean

CMakeFiles/Project.dir/depend:
	cd /home/dilyara/Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dilyara/Project /home/dilyara/Project /home/dilyara/Project/build /home/dilyara/Project/build /home/dilyara/Project/build/CMakeFiles/Project.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Project.dir/depend

