//
// Created by Miguel Chan on 2019-03-06.
//

#ifndef HELLO_SHADER_H
#define HELLO_SHADER_H

#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <exception>
#include <string>

class ShaderException : public std::exception {
private:
    std::string msg;
public:
    explicit ShaderException(const char* msg);
    const char * what() const noexcept override;
};

class Shader {
private:
    GLuint programId;
    static GLuint createShader(const char * name, const char* code, GLenum ShaderType);
public:
    Shader(const char* vertexPath, const char* fragPath);
    void use();
    GLuint getProgram();

};


#endif //HELLO_SHADER_H
