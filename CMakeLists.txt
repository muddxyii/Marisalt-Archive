cmake_minimum_required(VERSION 3.29)
project(Marisalt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_library(glad
        ${CMAKE_CURRENT_SOURCE_DIR}/glad/src/glad.c
        ${CMAKE_CURRENT_SOURCE_DIR}/glad/include/glad/glad.h
)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glad/include)

add_executable(Marisalt main.cpp)

target_include_directories(Marisalt PRIVATE
        ${OPENGL_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/glad/include
)

target_link_libraries(Marisalt PRIVATE
        ${OPENGL_LIBRARIES}
        glfw
        glad
)