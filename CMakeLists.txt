cmake_minimum_required(VERSION 3.29)
project(ClothSimCmake)

set(CMAKE_CXX_STANDARD 20)

add_executable(ClothSimCmake main.cpp)

target_sources(ClothSimCmake PRIVATE
        Particle.cpp
        Constraint.cpp
        Cloth.cpp
)

find_package(SDL2 REQUIRED)

target_include_directories(ClothSimCmake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ClothSimCmake PRIVATE ${SDL2_INCLUDE_DIRS})
target_include_directories(ClothSimCmake PRIVATE /usr/local/Cellar/glm/1.0.1/include)

target_link_libraries(ClothSimCmake ${SDL2_LIBRARIES})

if(APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-no_pie")
endif()
