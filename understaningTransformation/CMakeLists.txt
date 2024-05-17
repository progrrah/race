cmake_minimum_required(VERSION 3.21)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(X11 REQUIRED)

add_executable(race main.cpp)
add_library(graphick_lib STATIC graphicks.cpp graphicks.hpp)

target_link_libraries(graphick_lib PUBLIC OpenGL::GL GLUT::GLUT GLEW::GLEW X11::X11)
target_link_libraries(race PUBLIC graphick_lib OpenGL::GL GLUT::GLUT GLEW::GLEW X11::X11)
