# Miguel Chan - 2/28/2019
cmake_minimum_required(VERSION 3.10)
project(test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(SOURCE_DIR ${CMAKE_BINARY_DIR}/src)

FILE(GLOB SOURCE ${SOURCE_DIR}/*.cpp ${SOURCE_DIR}/*.c)
FILE(GLOB HEADER ${SOURCE_DIR}/*.h ${SOURCE_DIR}/*.hpp)

add_subdirectory(dependencies/GLFW)
include_directories(dependencies/include)

if (APPLE)
    set(os macos)
endif(APPLE)

if (UNIX AND NOT APPLE)
    set(os linux)
endif(UNIX AND NOT APPLE)

if (WIN32)
    set(os windows)
endif(WIN32)

set(EXECUTABLE_NAME ${PROJECT_NAME}-${os})

add_executable(${EXECUTABLE_NAME} ${SOURCE} ${HEADER})


FIND_PACKAGE(OpenGL REQUIRED)
if(OpenGL_FOUND)
    link_directories(${OpenGL_LIBRARY_DIRS})
    include_directories(${OpenGL_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_gl_LIBRARY})
endif(OpenGL_FOUND)

#FIND_PACKAGE(GLUT REQUIRED)
#if(GLUT_FOUND)
#    link_directories(${GLUT_LIBRARY_DIR})
#    include_directories(${GLUT_INCLUDE_DIR})
#    target_link_libraries(${EXECUTABLE_NAME} ${GLUT_LIBRARIES})
#endif(GLUT_FOUND)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
target_link_libraries(${EXECUTABLE_NAME} GLFW)
