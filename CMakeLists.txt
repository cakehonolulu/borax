cmake_minimum_required(VERSION 3.16)
project(Borax LANGUAGES C ASM)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src/include)

# Add the kernel source directory
add_subdirectory(src/kernel)
