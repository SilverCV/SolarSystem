cmake_minimum_required(VERSION 3.15)
project(SolarSystem)

set(CMAKE_CXX_STANDARD 14)


find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

include_directories(headers)
AUX_SOURCE_DIRECTORY(src SRC)
add_executable(SolarSystem  ${SRC})
target_link_libraries(SolarSystem ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )