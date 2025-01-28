cmake_minimum_required(VERSION 3.10)
project(Belote)

set(CMAKE_CXX_STANDARD 17)

# Include directory for header files
include_directories(include)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add executables
add_executable(Belote main.cpp menu.cpp Belote.cpp)  # Include all relevant cpp files

# Link SFML libraries
target_link_libraries(Belote sfml-graphics sfml-window sfml-system)
