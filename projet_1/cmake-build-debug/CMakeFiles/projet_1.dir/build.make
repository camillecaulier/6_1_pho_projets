# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projet_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projet_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projet_1.dir/flags.make

CMakeFiles/projet_1.dir/philosopher_problem.c.o: CMakeFiles/projet_1.dir/flags.make
CMakeFiles/projet_1.dir/philosopher_problem.c.o: ../philosopher_problem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/projet_1.dir/philosopher_problem.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projet_1.dir/philosopher_problem.c.o   -c /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/philosopher_problem.c

CMakeFiles/projet_1.dir/philosopher_problem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet_1.dir/philosopher_problem.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/philosopher_problem.c > CMakeFiles/projet_1.dir/philosopher_problem.c.i

CMakeFiles/projet_1.dir/philosopher_problem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet_1.dir/philosopher_problem.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/philosopher_problem.c -o CMakeFiles/projet_1.dir/philosopher_problem.c.s

CMakeFiles/projet_1.dir/producer_consumer.c.o: CMakeFiles/projet_1.dir/flags.make
CMakeFiles/projet_1.dir/producer_consumer.c.o: ../producer_consumer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/projet_1.dir/producer_consumer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/projet_1.dir/producer_consumer.c.o   -c /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/producer_consumer.c

CMakeFiles/projet_1.dir/producer_consumer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/projet_1.dir/producer_consumer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/producer_consumer.c > CMakeFiles/projet_1.dir/producer_consumer.c.i

CMakeFiles/projet_1.dir/producer_consumer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/projet_1.dir/producer_consumer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/producer_consumer.c -o CMakeFiles/projet_1.dir/producer_consumer.c.s

# Object files for target projet_1
projet_1_OBJECTS = \
"CMakeFiles/projet_1.dir/philosopher_problem.c.o" \
"CMakeFiles/projet_1.dir/producer_consumer.c.o"

# External object files for target projet_1
projet_1_EXTERNAL_OBJECTS =

projet_1: CMakeFiles/projet_1.dir/philosopher_problem.c.o
projet_1: CMakeFiles/projet_1.dir/producer_consumer.c.o
projet_1: CMakeFiles/projet_1.dir/build.make
projet_1: CMakeFiles/projet_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable projet_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projet_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projet_1.dir/build: projet_1

.PHONY : CMakeFiles/projet_1.dir/build

CMakeFiles/projet_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projet_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projet_1.dir/clean

CMakeFiles/projet_1.dir/depend:
	cd /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1 /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1 /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/cmake-build-debug /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/cmake-build-debug /mnt/c/Users/Camil/OneDrive/Documents/bac_3/linfo1253/6_1_pho_projets/projet_1/cmake-build-debug/CMakeFiles/projet_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projet_1.dir/depend

