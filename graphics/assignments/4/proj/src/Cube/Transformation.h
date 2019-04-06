//
// Created by Miguel Chan on 2019-04-03.
//

#ifndef TRANSFORMATION_TRANSFORMATION_H
#define TRANSFORMATION_TRANSFORMATION_H

#include <glm/glm.hpp>

class Transform {
public:
    virtual glm::mat4 getTransformMatrix() = 0;
    virtual ~Transform() = default;
};

class StaticCube : public Transform {
public:
    glm::mat4 getTransformMatrix() override;
};

class TranslationCube : public Transform {
private:
    float movingLength = 0.5;
public:
    bool horizontal = true, vertical = false;
    void setMovingLength(float n);
    glm::mat4 getTransformMatrix() override;
    TranslationCube(float movingLength = 0.5);
};

class RotationCube: public Transform {
public:
    glm::mat4 getTransformMatrix() override;
};

#endif //TRANSFORMATION_TRANSFORMATION_H
