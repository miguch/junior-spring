//
// Created by Miguel Chan on 2019-03-19.
//

#include "Bresenham.h"
#include <iostream>
#include <glad/glad.h>
#include <cmath>


using namespace std;

auto vertexAttribSetter = []() {
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    //Color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
};

pair<GLuint, GLuint> genVertex(int size, float *data,
                               const function<void()> &vertexAttribCallback) {
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    if (size != 0 && data != nullptr) {
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }
    vertexAttribCallback();
    // Unbind
    glBindVertexArray(0);
    return make_pair(VAO, VBO);
}

Bresenham::Bresenham(GLFWwindow *window) : window(window), shader("shaders/vert.glsl", "shaders/frag.glsl") {
    updateWindowSize();
    tie(VAO, VBO) = genVertex(0, nullptr, vertexAttribSetter);
}

inline void pushColor(float *color, vector<float> &data) {
    data.push_back(color[0]);
    data.push_back(color[1]);
    data.push_back(color[2]);
}

vector<BresenhamLine::Point<GLint>> getBresenhamLine(GLint x1, GLint y1, GLint x2, GLint y2) {
    vector<BresenhamLine::Point<GLint>> result;
    // draw line from left to right and slope's absolute value must be smaller than 1
    bool isSteep = abs(y2 - y1) > abs(x2 - x1);
    // if line is steep, rotate the coordinate to draw
    auto putPoint = [&](GLint x, GLint y) {
        if (isSteep) {
            result.push_back({y, x});
        } else {
            result.push_back({x, y});
        }
    };
    if (isSteep) {
        swap(x1, y1);
        swap(x2, y2);
    }
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    GLint deltaX = x2 - x1;
    GLint deltaY = abs(y2 - y1);
    GLint p = 2 * deltaY - deltaX;
    GLint yStep = (y1 < y2) ? 1 : -1;
    GLint pStep1 = 2 * deltaY;
    GLint pStep2 = 2 * (deltaY - deltaX);

    putPoint(x1, y1);

    for (int x = x1 + 1, y = y1; x <= x2; x++) {
        if (p <= 0) {
            p += pStep1;
        } else {
            y += yStep;
            p += pStep2;
        }
        putPoint(x, y);
    }
    return result;
}

void BresenhamLine::draw() {
    Bresenham::draw();
    // Recalculate line only when window size or line parameters have changed
    if (updateWindowSize() || updateParameters()) {
        vector<Point<GLint>> linesPoints;
        int linesSeq[3][2] = {{0, 1},
                              {0, 2},
                              {1, 2}};
        for (auto seq : linesSeq) {
            //OpenGL coordinate to display coordinate
            Point<GLint> point1 = {GLint(vertices[seq[0]].x * windowWidth / 2),
                                   GLint(vertices[seq[0]].y * windowHeight / 2)};
            Point<GLint> point2 = {GLint(vertices[seq[1]].x * windowWidth / 2),
                                   GLint(vertices[seq[1]].y * windowHeight / 2)};
            auto line = getBresenhamLine(point1.x, point1.y, point2.x, point2.y);
            linesPoints.insert(end(linesPoints), begin(line), end(line));
        }
        pointsData.clear();
        for (const auto &point: linesPoints) {
            //To opengl coordinate
            pointsData.push_back(static_cast<float>(point.x) / windowWidth * 2);
            pointsData.push_back(static_cast<float>(point.y) / windowHeight * 2);
            // z-axis
            pointsData.push_back(0);
            //color
            pointsData.push_back(r);
            pointsData.push_back(g);
            pointsData.push_back(b);
        }
    }
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, pointsData.size() * sizeof(GLfloat), pointsData.data(), GL_DYNAMIC_DRAW);
    glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(pointsData.size() / 6));
}

BresenhamLine::BresenhamLine(GLFWwindow *window, const std::array<GLfloat, 6> &vertices) : Bresenham(window) {
    setVertices(vertices);
    setColor(1, 1, 1);
}

void BresenhamLine::setVertices(const std::array<GLfloat, 6> &vertices) {
    for (int i = 0; i < 3; i++) {
        Point<GLfloat> vertex = {vertices[i * 2], vertices[i * 2 + 1]};
        this->vertices[i] = vertex;
    }
    updatedParameters = true;
}

void BresenhamCircle::setColor(GLfloat r, GLfloat g, GLfloat b) {
    this->r = r;
    this->g = g;
    this->b = b;
    updatedParameters = true;
}

void BresenhamLine::setColor(GLfloat r, GLfloat g, GLfloat b) {
    this->r = r;
    this->g = g;
    this->b = b;
    updatedParameters = true;
}

bool BresenhamLine::updateParameters() {
    if (updatedParameters) {
        updatedParameters = false;
        return true;
    }
    return false;
}

vector<BresenhamCircle::Point<GLint>> getCirclePoints(GLint cx, GLint cy, GLint radius) {
    GLint d = 3 - 2 * radius;

    vector<BresenhamCircle::Point<GLint>> result;
    //Draw 8 parts of the circle
    auto putPoints = [&](GLint dx, GLint dy) {
        result.push_back({cx + dx, cx + dy});
        result.push_back({cx + dx, cx - dy});
        result.push_back({cx - dx, cx + dy});
        result.push_back({cx - dx, cx - dy});
        result.push_back({cx + dy, cx + dx});
        result.push_back({cx + dy, cx - dx});
        result.push_back({cx - dy, cx + dx});
        result.push_back({cx - dy, cx - dx});
    };
    for (int x = 0, y = radius; x <= y; x++) {
        if (d >= 0) {
            y--;
            d += 4 * (x - y) + 10;
        } else {
            d += 4 * x + 6;
        }
        putPoints(x, y);
    }
    return result;
}


void BresenhamCircle::draw() {
    Bresenham::draw();
    if (updateWindowSize() || updateParameters()) {
        //To pixel coordinate
        int cx = center.x * windowWidth, cy = center.y * windowHeight;
        int pr = radius * min(windowHeight, windowWidth);
        auto points = getCirclePoints(cx, cy, pr);
        pointsData.clear();
        for (const auto & point : points) {
            pointsData.push_back(static_cast<float>(point.x) / windowWidth * 2);
            pointsData.push_back(static_cast<float>(point.y) / windowHeight * 2);
            pointsData.push_back(0);
            pointsData.push_back(r);
            pointsData.push_back(g);
            pointsData.push_back(b);
        }
    }
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, pointsData.size() * sizeof(GLfloat), pointsData.data(), GL_DYNAMIC_DRAW);
    glDrawArrays(GL_POINTS, 0, pointsData.size() / 6);
}

BresenhamCircle::BresenhamCircle(GLFWwindow *window, GLfloat centerX, GLfloat centerY, GLfloat radius): Bresenham(window) {
    setCenter(centerX, centerY);
    setRadius(radius);
    setColor(1, 1, 1);
}

void BresenhamCircle::setRadius(GLfloat r) {
    updatedParameters = true;
    radius = r;
}

void BresenhamCircle::setCenter(GLfloat x, GLfloat y) {
    updatedParameters = true;
    center = {x, y};
}

bool BresenhamCircle::updateParameters() {
    if (updatedParameters) {
        updatedParameters = false;
        return true;
    }
    return false;
}

// Returns true if there has been a change in the window size
bool Bresenham::updateWindowSize() {
    int w, h;
    glfwGetWindowSize(window, &w, &h);
    if (windowWidth != w || windowHeight != h) {
        windowWidth = w;
        windowHeight = h;
        return true;
    }
    return false;
}

Bresenham::~Bresenham() = default;

void Bresenham::draw() {
    shader.use();
}
