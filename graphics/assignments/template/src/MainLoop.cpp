//
// Created by Miguel Chan on 2019-03-22.
//

#include "MainLoop.h"

#include <array>
#include <unordered_map>
#include <memory>
#include <cmath>
#include <ctime>
#include <thread>
#include <exception>

#include "shader.h"

using namespace std;

enum MODE {
    TRIANGLE_OUTLINE, CIRCLE, TRIANGLE_FILLED
};

const char *glsl_version = "#version 150";

void MainLoop::loop(GLFWwindow *window) {

    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);



    while (!glfwWindowShouldClose(window)) {
        auto start = clock();
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        {
            if (ImGui::BeginMainMenuBar()) {
                if (ImGui::BeginMenu("Mode")) {

                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }
        }
        {
            ImGui::Begin("Window");

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

