//
// Created by Miguel Chan on 2019-03-19.
//

#ifndef DRAWLINE_BRESENHAM_H
#define DRAWLINE_BRESENHAM_H

#include <array>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "shader.h"

class Bresenham {
public:
    template <class T>
    struct Point {
        T x, y;
    };
protected:
    int windowWidth, windowHeight;
    GLFWwindow* window;
    Shader shader;
    GLuint VAO, VBO;

public:
    explicit Bresenham(GLFWwindow* window);
    virtual void draw();
    bool updateWindowSize();
    virtual ~Bresenham();
};

class BresenhamLine : public Bresenham {
private:
    GLfloat r, g, b;
    std::array<Point<GLfloat>, 3> vertices;
    std::vector<float> pointsData;
    bool updatedParameters;
    bool updateParameters();

public:
    BresenhamLine(GLFWwindow* window, const std::array<GLfloat, 6>& vertices);
    void draw() override;
    void setVertices(const std::array<GLfloat, 6>& vertices);
    void setColor(GLfloat r, GLfloat g, GLfloat b);
};

class BresenhamCircle : public Bresenham {
private:
    GLfloat r, g, b;
    Point<GLfloat> center;
    GLfloat radius;
    bool updatedParameters;
    bool updateParameters();
    std::vector<float> pointsData;

public:
    BresenhamCircle(GLFWwindow* window, GLfloat centerX, GLfloat centerY, GLfloat radius);
    void draw() override;
    void setCenter(GLfloat x, GLfloat y);
    void setRadius(GLfloat r);
    void setColor(GLfloat r, GLfloat g, GLfloat b);
};

#endif //DRAWLINE_BRESENHAM_H
