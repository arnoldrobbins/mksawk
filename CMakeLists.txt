cmake_minimum_required(VERSION 3.10)
project(mksawk C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find required packages
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# Generate parser files from awk.y
BISON_TARGET(awk_parser awk.y ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c
             DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/y.tab.h)

# Include directories
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR})

# Define source files
set(SOURCES
    awk0.c
    awk1.c
    awk2.c
    awk3.c
    awk4.c
    wsprintf.c
    ${BISON_awk_parser_OUTPUTS}
)

# Create executable
add_executable(mksawk ${SOURCES})

# Link required libraries
target_link_libraries(mksawk m)

# Enable warnings
target_compile_options(mksawk PRIVATE -Wall -Wextra)
