cmake_minimum_required(VERSION 3.21)
project(race VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(X11 REQUIRED)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_executable(race main.cpp)
add_library(race_lib STATIC lib.cpp library.hpp)
add_library(interLib STATIC interaction.cpp interaction.hpp)

# add_library()
target_link_libraries(race_lib PUBLIC OpenGL::GL GLUT::GLUT GLEW::GLEW X11::X11)
target_link_libraries(interLib PUBLIC OpenGL::GL GLUT::GLUT GLEW::GLEW X11::X11)
target_link_libraries(race PUBLIC race_lib interLib OpenGL::GL GLUT::GLUT GLEW::GLEW X11::X11)
