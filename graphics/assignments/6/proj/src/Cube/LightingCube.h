//
// Created by Miguel Chan on 2019-04-23.
//

#ifndef CAMERA_LIGHTINGCUBE_H
#define CAMERA_LIGHTINGCUBE_H


#include "BaseCube.h"
#include "../Shader/shader.h"
#include "../Utils/Utils.h"


class LightingCube : public BaseCube {
private:
    std::unique_ptr<Utils::VertexArrayBuffer> vertexBuffer;
public:
    const std::unique_ptr<Utils::VertexArrayBuffer> &getVertexBuffer() const;

private:
    static std::unique_ptr<Shader> phongShader;
    static std::unique_ptr<Shader> gouraudShader;
    float length;
    float width;
    float height;
    glm::vec3 lightColor, objectColor;
    glm::vec3 lightPos, viewPos;
    bool usingPhong;
public:
    bool isUsingPhong() const;

    void setUsingPhong(bool usingPhong);

public:
    const glm::vec3 &getViewPos() const;

    void setViewPos(const glm::vec3 &viewPos);

    const glm::vec3 &getLightPos() const;

    void setLightPos(const glm::vec3 &lightPos);

    const glm::vec3 &getLightColor() const;

    void setLightColor(const glm::vec3 &lightColor);

    const glm::vec3 &getObjectColor() const;

    void setObjectColor(const glm::vec3 &objectColor);

    void draw(Transform *transformer);

    float ambientStrength;
    float specularStrength;
    float diffuseStrength;
    int shininess;

    explicit LightingCube(glm::vec3 colors, float length = 1, float width = 1, float height = 1);

    LightingCube(glm::vec3 colors, std::shared_ptr<Utils::VertexBufferObject> vbo);
};


#endif //CAMERA_LIGHTINGCUBE_H
