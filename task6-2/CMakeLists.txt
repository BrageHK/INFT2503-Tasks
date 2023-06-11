cmake_minimum_required(VERSION 3.1)

# Project name
project(BoostAsioExample)

# Enable C++11 or later
set(CMAKE_CXX_STANDARD 11)

# Find Boost
find_package(Boost 1.66.0 COMPONENTS system REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    # Target executable name and its sourcefiles
    add_executable(${PROJECT_NAME} main.cpp)

    # Linking with the required libraries
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Could not find Boost!")
endif()
