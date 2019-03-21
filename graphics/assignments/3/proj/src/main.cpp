#include <iostream>
#include <memory>
#include <cmath>
#include <ctime>
#include <thread>
#include <exception>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <glm/glm.hpp>
#include <vector>

#include "shader.h"
#include "Bresenham.h"

using namespace std;

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const char *glsl_version;

enum MODE {
    TRIANGLE_OUTLINE = 0, CIRCLE, TRIANGLE_FILLED
};


void mainloop(GLFWwindow *window) {

    array<GLfloat, 6> triangle_vertices = {
            0, 0.7, -0.7, -0.7, 0.7, -0.7
    };
    array<GLfloat, 3> outline_color = {
            1,1,1
    };
    array<GLfloat, 2> circle_center = {0, 0};
    GLfloat circle_radius = 0.3;
    array<GLfloat, 3> circle_color = {
            1,1,1
    };

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);


    array<unique_ptr<Bresenham>, 3> drawers;
    drawers[TRIANGLE_OUTLINE] = make_unique<BresenhamLine>(window, triangle_vertices);
    drawers[CIRCLE] = make_unique<BresenhamCircle>(window, circle_center[0], circle_center[1], circle_radius);
    MODE current_mode = TRIANGLE_OUTLINE;

    while (!glfwWindowShouldClose(window)) {
        auto start = clock();
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        auto &drawer = drawers[current_mode];
        drawer->draw();

        bool updateVertices = false;

        {
            ImGui::Begin("Bresenham");
            if (current_mode != CIRCLE && ImGui::Button("Circle")) {
                current_mode = CIRCLE;
            }
            if (current_mode != TRIANGLE_OUTLINE && ImGui::Button("Triangle Outline")) {
                current_mode = TRIANGLE_OUTLINE;
            }
            if (current_mode != TRIANGLE_FILLED && ImGui::Button("Triangle Rasterized")) {
                current_mode = TRIANGLE_FILLED;
            }
            switch (current_mode) {
                case TRIANGLE_OUTLINE:
                    ImGui::Text("Vertices Position:");
                    ImGui::Text("a: ");
                    updateVertices = ImGui::InputFloat2("##a", &triangle_vertices[0]) || updateVertices;
                    ImGui::Text("b: ");
                    updateVertices = ImGui::InputFloat2("##b", &triangle_vertices[2]) || updateVertices;
                    ImGui::Text("x: ");
                    updateVertices = ImGui::InputFloat2("##c", &triangle_vertices[4]) || updateVertices;
                    if (updateVertices) {
                        dynamic_cast<BresenhamLine *>(drawer.get())->setVertices(triangle_vertices);
                    }
                    ImGui::Text("Color: ");
                    if (ImGui::ColorEdit3("##Triangle-outline", outline_color.data())) {
                        dynamic_cast<BresenhamLine *>(drawer.get())->setColor(outline_color[0], outline_color[1], outline_color[2]);
                    }
                    break;
                case CIRCLE:
                    ImGui::Text("Center Position:");
                    if (ImGui::InputFloat2("##center", circle_center.data())) {
                        dynamic_cast<BresenhamCircle *>(drawer.get())->setCenter(circle_center[0], circle_center[1]);
                    }
                    ImGui::Text("Radius:");
                    if (ImGui::InputFloat("##radius", &circle_radius)) {
                        dynamic_cast<BresenhamCircle *>(drawer.get())->setRadius(circle_radius);
                    }
                    ImGui::Text("Color: ");
                    if (ImGui::ColorEdit3("##circle-outline", circle_color.data())) {
                        dynamic_cast<BresenhamCircle *>(drawer.get())->setColor(circle_color[0], circle_color[1], circle_color[2]);
                    }
                    break;
                case TRIANGLE_FILLED:
                    break;
            }
            ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                        ImGui::GetIO().Framerate);
            ImGui::End();
        }


        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);

        glfwPollEvents();
        auto waitTime = static_cast<long long>(
                1000.0 / 60 - double(clock() - start) / CLOCKS_PER_SEC * 1000);
        // Limit fps
        this_thread::sleep_for(chrono::milliseconds(waitTime));
    }

}

int main() {
    glfwInit();

    glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
#if defined(__APPLE__)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    try {
        mainloop(window);
    } catch (exception &err) {
        cerr << err.what() << endl;
        exit(1);
    }

    // clear GLFW resources
    glfwTerminate();
    return 0;
}
