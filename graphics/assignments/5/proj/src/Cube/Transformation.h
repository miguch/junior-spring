//
// Created by Miguel Chan on 2019-04-03.
//

#ifndef TRANSFORMATION_TRANSFORMATION_H
#define TRANSFORMATION_TRANSFORMATION_H

#include <glm/glm.hpp>
#include "../Camera/Camera.h"

class Transform {
public:
    virtual glm::mat4 getTransformMatrix() = 0;
    virtual ~Transform() = default;
};


class OrthoTransform : public Transform {
private:

public:
    glm::mat4 getTransformMatrix() override;
    OrthoTransform(float left, float right, float bottom, float top, float near, float far);
    float left, right, bottom, top, near, far;
};

class PerspectiveTransform : public Transform {
private:

public:
    glm::mat4 getTransformMatrix() override;
    PerspectiveTransform(float fovy_degree, float aspect, float near, float far);
    float fovy_degree, aspect, near, far;
};

class ViewChangeTransform : public Transform {
private:

public:
    glm::mat4 getTransformMatrix() override;
    ViewChangeTransform();
    int axis;
};

class MovingCamTransform : public Transform {
private:

public:
    glm::mat4 getTransformMatrix() override;

    explicit MovingCamTransform(const Camera& cam);

    Camera cam;
};
#endif //TRANSFORMATION_TRANSFORMATION_H
