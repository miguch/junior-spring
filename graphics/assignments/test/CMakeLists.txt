cmake_minimum_required(VERSION 3.10)
project(test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SOURCE_DIR ${CMAKE_BINARY_DIR}/src)

FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLUT REQUIRED)

FILE(GLOB SOURCE ${SOURCE_DIR}/*.cpp)
FILE(GLOB HEADER ${SOURCE_DIR}/*.h)

if (APPLE)
    set(os macos)
endif(APPLE)

if (UNIX AND NOT APPLE)
    set(os linux)
endif(UNIX AND NOT APPLE)

if (WIN32)
    set(os windows)
endif(WIN32)

add_executable(test-${os} ${SOURCE} ${HEADER})

if(OpenGL_FOUND)
    link_directories(${OpenGL_LIBRARY_DIRS})
    include_directories(${OpenGL_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME}-${os} ${OPENGL_gl_LIBRARY})
endif(OpenGL_FOUND)


if(GLUT_FOUND)
    link_directories(${GLUT_LIBRARY_DIR})
    include_directories(${GLUT_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME}-${os} ${GLUT_LIBRARIES})
endif(GLUT_FOUND)



