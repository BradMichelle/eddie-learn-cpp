cmake_minimum_required(VERSION 3.26)
project(cpp_learning VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add debug symbols
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_BUILD_TYPE Debug)

add_executable(cpp_learning main.cpp)

# Add one executable per issue file
file(GLOB ISSUE_SOURCES "issues/*.cpp")
foreach(issue_src IN LISTS ISSUE_SOURCES)
    get_filename_component(issue_name ${issue_src} NAME_WE)
    add_executable(${issue_name} ${issue_src})
endforeach()
