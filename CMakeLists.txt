cmake_minimum_required(VERSION 3.29)
project(ClothSimCmake)

set(CMAKE_CXX_STANDARD 20)

add_executable(ClothSimCmake main.cpp)

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Include SDL2 directories
target_include_directories(ClothSimCmake PRIVATE ${SDL2_INCLUDE_DIRS})

# Link SDL2 libraries
target_link_libraries(ClothSimCmake ${SDL2_LIBRARIES})

if(APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-no_pie")
endif()
