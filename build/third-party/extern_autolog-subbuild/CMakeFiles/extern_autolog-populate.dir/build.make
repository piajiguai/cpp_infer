# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild

# Utility rule file for extern_autolog-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/extern_autolog-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/extern_autolog-populate.dir/progress.make

CMakeFiles/extern_autolog-populate: CMakeFiles/extern_autolog-populate-complete

CMakeFiles/extern_autolog-populate-complete: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-install
CMakeFiles/extern_autolog-populate-complete: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-mkdir
CMakeFiles/extern_autolog-populate-complete: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-download
CMakeFiles/extern_autolog-populate-complete: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-update
CMakeFiles/extern_autolog-populate-complete: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-patch
CMakeFiles/extern_autolog-populate-complete: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-configure
CMakeFiles/extern_autolog-populate-complete: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-build
CMakeFiles/extern_autolog-populate-complete: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-install
CMakeFiles/extern_autolog-populate-complete: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'extern_autolog-populate'"
	/usr/local/bin/cmake -E make_directory /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles
	/usr/local/bin/cmake -E touch /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles/extern_autolog-populate-complete
	/usr/local/bin/cmake -E touch /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-done

autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-update:
.PHONY : autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-update

autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-build: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'extern_autolog-populate'"
	cd /home/zjl/123/cpp_infer/build/third-party/extern_autolog-build && /usr/local/bin/cmake -E echo_append
	cd /home/zjl/123/cpp_infer/build/third-party/extern_autolog-build && /usr/local/bin/cmake -E touch /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-build

autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-configure: autolog/tmp/extern_autolog-populate-cfgcmd.txt
autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-configure: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'extern_autolog-populate'"
	cd /home/zjl/123/cpp_infer/build/third-party/extern_autolog-build && /usr/local/bin/cmake -E echo_append
	cd /home/zjl/123/cpp_infer/build/third-party/extern_autolog-build && /usr/local/bin/cmake -E touch /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-configure

autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-download: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-gitinfo.txt
autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-download: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'extern_autolog-populate'"
	cd /home/zjl/123/cpp_infer/build/third-party && /usr/local/bin/cmake -P /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/tmp/extern_autolog-populate-gitclone.cmake
	cd /home/zjl/123/cpp_infer/build/third-party && /usr/local/bin/cmake -E touch /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-download

autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-install: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'extern_autolog-populate'"
	cd /home/zjl/123/cpp_infer/build/third-party/extern_autolog-build && /usr/local/bin/cmake -E echo_append
	cd /home/zjl/123/cpp_infer/build/third-party/extern_autolog-build && /usr/local/bin/cmake -E touch /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-install

autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'extern_autolog-populate'"
	/usr/local/bin/cmake -Dcfgdir= -P /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/tmp/extern_autolog-populate-mkdirs.cmake
	/usr/local/bin/cmake -E touch /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-mkdir

autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-patch: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'extern_autolog-populate'"
	/usr/local/bin/cmake -E echo_append
	/usr/local/bin/cmake -E touch /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-patch

autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-update:
.PHONY : autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-update

autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-test: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'extern_autolog-populate'"
	cd /home/zjl/123/cpp_infer/build/third-party/extern_autolog-build && /usr/local/bin/cmake -E echo_append
	cd /home/zjl/123/cpp_infer/build/third-party/extern_autolog-build && /usr/local/bin/cmake -E touch /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-test

autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-update: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'extern_autolog-populate'"
	cd /home/zjl/123/cpp_infer/build/third-party/extern_autolog-src && /usr/local/bin/cmake -P /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/autolog/tmp/extern_autolog-populate-gitupdate.cmake

extern_autolog-populate: CMakeFiles/extern_autolog-populate
extern_autolog-populate: CMakeFiles/extern_autolog-populate-complete
extern_autolog-populate: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-build
extern_autolog-populate: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-configure
extern_autolog-populate: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-download
extern_autolog-populate: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-install
extern_autolog-populate: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-mkdir
extern_autolog-populate: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-patch
extern_autolog-populate: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-test
extern_autolog-populate: autolog/src/extern_autolog-populate-stamp/extern_autolog-populate-update
extern_autolog-populate: CMakeFiles/extern_autolog-populate.dir/build.make
.PHONY : extern_autolog-populate

# Rule to build all files generated by this target.
CMakeFiles/extern_autolog-populate.dir/build: extern_autolog-populate
.PHONY : CMakeFiles/extern_autolog-populate.dir/build

CMakeFiles/extern_autolog-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/extern_autolog-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/extern_autolog-populate.dir/clean

CMakeFiles/extern_autolog-populate.dir/depend:
	cd /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild /home/zjl/123/cpp_infer/build/third-party/extern_autolog-subbuild/CMakeFiles/extern_autolog-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/extern_autolog-populate.dir/depend

