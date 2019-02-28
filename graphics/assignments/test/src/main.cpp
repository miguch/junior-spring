#if defined(__APPLE__)
#define GL_SILENCE_DEPRECATION
#else
#include "msvc_gl.h"
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glEnd();
    glFlush();

}

int main(int argc, char** argv)
{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE);
//    glutInitWindowSize(300, 300);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Hello world :D");
//    glutDisplayFunc(displayMe);
//    glutMainLoop();
//    cout << glGetString(GL_VERSION) << endl;
//    printf("%s\n", glGetString(GL_VERSION));

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 0;
}
