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

#include "Shader/shader.h"
#include "Cube/Cube.h"
#include "Utils/Utils.h"
#include "Cube/Transformation.h"

using namespace std;

enum MODE {
    STATIC, TRANSLATION, ROTATION, SCALING
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

    Cube cube("resources/GreyOak.jpg", 4, 4, 4);

    unordered_map<MODE, unique_ptr<Transform>> trans;
    trans[MODE::STATIC] = make_unique<StaticCube>();
    trans[MODE::TRANSLATION] = make_unique<TranslationCube>(2);
    trans[MODE::ROTATION] = make_unique<RotationCube>();

    MODE current = MODE::STATIC;

    while (!glfwWindowShouldClose(window)) {
        auto start = clock();
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        cube.draw(trans[current].get());

        {
            if (ImGui::BeginMainMenuBar()) {
                if (ImGui::BeginMenu("Mode")) {
                    if (current != MODE::STATIC && ImGui::MenuItem("Static")) {
                        current = MODE::STATIC;
                    }
                    if (current != MODE::TRANSLATION && ImGui::MenuItem("Translation")) {
                        current = MODE::TRANSLATION;
                    }
                    if (current != MODE::ROTATION && ImGui::MenuItem("Rotation")) {
                        current = MODE::ROTATION;
                    }
                    if (current != MODE::SCALING && ImGui::MenuItem("Scaling")) {
                        current = MODE::SCALING;
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMainMenuBar();
            }
        }

        {
            ImGui::Begin("Options");
            static bool depthTest = true;
            ImGui::Checkbox("Depth Test", &depthTest);
            if (depthTest) {
                Utils::enableDepthTest();
            } else {
                Utils::disableDepthTest();
            }

            if (current == MODE::TRANSLATION) {
                ImGui::Checkbox("Horizontal", &dynamic_cast<TranslationCube*>(trans[MODE::TRANSLATION].get())->horizontal);
                ImGui::Checkbox("Vertical", &dynamic_cast<TranslationCube*>(trans[MODE::TRANSLATION].get())->vertical);
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

