# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/chuby/local_prj/umd-lpc1769/Led_CUBE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chuby/local_prj/umd-lpc1769/Led_CUBE

# Utility rule file for gdb.

# Include the progress variables for this target.
include CMakeFiles/gdb.dir/progress.make

CMakeFiles/gdb:
	/usr/local/lpcxpresso_5.1.2_2065/lpcxpresso/tools/bin/arm-none-eabi-gdb --eval-command="target extended-remote | /usr/local/lpcxpresso_5.1.2_2065/lpcxpresso/bin/crt_emu_cm3_nxp -wire=winusb -pLPC1769 -vendor=NXP -2 -g" --eval-command="set remotetimeout 5000" --eval-command="set mem inaccessible-by-default off" --eval-command="mon ondisconnect cont" --eval-command="set arm force-mode thumb" --eval-command="mon semihosting ena" --exec="/home/chuby/local_prj/umd-lpc1769/Led_CUBE/bin/Led_CUBE.axf" --symbols="/home/chuby/local_prj/umd-lpc1769/Led_CUBE/bin/Led_CUBE.axf.debug"

gdb: CMakeFiles/gdb
gdb: CMakeFiles/gdb.dir/build.make
.PHONY : gdb

# Rule to build all files generated by this target.
CMakeFiles/gdb.dir/build: gdb
.PHONY : CMakeFiles/gdb.dir/build

CMakeFiles/gdb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gdb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gdb.dir/clean

CMakeFiles/gdb.dir/depend:
	cd /home/chuby/local_prj/umd-lpc1769/Led_CUBE && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chuby/local_prj/umd-lpc1769/Led_CUBE /home/chuby/local_prj/umd-lpc1769/Led_CUBE /home/chuby/local_prj/umd-lpc1769/Led_CUBE /home/chuby/local_prj/umd-lpc1769/Led_CUBE /home/chuby/local_prj/umd-lpc1769/Led_CUBE/CMakeFiles/gdb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gdb.dir/depend

