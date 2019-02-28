# Homework 1

1. **对计算机图形学的理解**

   计算机图形学是一门研究如何在计算机中进行图形计算与显示的学科。在一定程度上，如果说计算机视觉的目的是从图像到知识，那计算机图形学则是从知识生成图像。

   计算机图形学中要生成出具有真实感的图像，需要经过计算机图形学中的几大部分的处理：

   - 建模：通过构建三维物件的集合模型进行物件的表达，这是计算机图形学的基础，其他部分的处理都需要建立在建模的基础上；
   - 渲染：将模型生成图像的过程，通过光线追踪等方法创造具有真实或非真实的图像；
   - 动画：通过连续的静态图像中的物体随着时间进行位移或变形，来产生运动的视觉效果；
   - 人机交互：涉及人与计算机的交互方式，通过图形学的多种技术增强人与机器的交互体验与丰富交互的方式。

   计算机图形学的应用广泛，如电影、广告、软件 GUI、游戏等领域都需要用到计算机图形学。

2. **什么是OpenGL? OpenGL ES? Web GL? Vulkan? DirectX?**

   OpenGL是一个包含了一系列操作图形与图像的函数的 API 规范，由 Khronos Group（包含了显卡厂商、操作系统设计人员及其他技术公司） 制定与维护。OpenGL 规范了每个函数的执行方式与输出，而 OpenGL 的实现则由显卡、电脑厂商或其他开发者进行。使用 OpenGL 时的执行过程为改变 OpenGL 的上下文状态，改变后当下一次绘制发生时则会根据改变后的状态输出图形。

   OpenGL ES是 OpenGL 的子集，设计的目的是为提供给手机、游戏主机等嵌入式设备使用，相较于 OpenGL，OpenGL ES 去除了多个非绝对必要的特性。GLUT 和 GLU 库在 OpenGL ES 中不可用。

   WebGL是一套 JavaScript API，由 Khronos Group 维护，可在搭载有支持 WebGL 特性的 GPU 的设备上运行的对 WebGL 兼容的 Web 浏览器中使用，无需使用插件。WebGL 基于 OpenGL ES，利用了 HTML5中的 canvas 元素。

   Vulkan 是一个图形与计算的 API 规范，基于 AMD 的 Mantle 构建，同样由 Khronos Group 发布，可在多种操作系统上运行（macOS 和 iOS 上需使用 MoltenVK 在 Metal API 上运行），相对于 OpenGL，Vulkan 有着更好的多核 CPU 优化，并统一了图形和计算的 API，不需再分为 OpenCL 与 OpenGL。

   DirectX 是一套由微软发布的用于多媒体和游戏开发的 API，使用 C++ 实现，包含 Direct2D、Direct3D等多部分。目前最新的版本为 DirectX 12。DirectX 在 Windows、Xbox 等平台中广泛用于游戏和三维图形的开发。DirectX 的 SDK 包含了一套可分发的二进制运行时库、文档以及编程使用的头文件。

3. **`gl.h` `glu.h` `glew.h` 的作用分别是什么?**

   `gl.h`: 包含了 OpenGL-1.1 的函数与符号定义，任何超出 OpenGL-1.1 版本的功能都需要使用其他头文件引入；

   `glu.h`: OpenGL Utility Library, 包含一系列便于使用的函数，作用是通过这些简单的函数，通过调用 OpenGL 库来实现一些较复杂的功能，已长期未更新；

   `glew.h`：OpenGL Extension Wrangler Library，作用是引入上面提到的超出 OpenGL-1.1版本的扩展功能，包含该头文件后即可使用当前平台和硬件下所支持的所有扩展功能，GLEW 将在程序运行时决定需要载入的的现代 OpenGL API。

4. **使用GLFW和freeglut的目的是什么？**

   glut 的全称为 OpenGL Utility Toolkit，主要用于处理系统级的 I/O，如定义、控制视窗与监听鼠标、键盘输入等，用于控制包含 OpenGL 上下文的视窗。但 GLUT 已不再受维护，开源的 freeglut 成为其替代品，提供的 API 为 GLUT 的超集。

   GLFW的全称为 Graphics Library Framework，其作用是令开发者可以创建和管理视窗与 OpenGL 上下文，也可以处理键盘、鼠标、游戏手柄等输入。

   freeglut 与 GLFW 都建立在 OpenGL 之上，可以实现类似的处理 I/O 的功能，其区别是 GLUT 通过回调工作，而且实现了 event loop，而 GLFW 中则由开发者来决定 event loop 的实现。

5. **选择一个SIGGRAPH 2017/2018上 你最喜欢的专题，介绍该专题是做什么的，使用了什么CG技术？**

   [A Multi-Scale Model for Simulating Liquid-Hair Interactions ](http://www.cs.columbia.edu/cg/liquidhair/) 该专题提出了对液体中的毛发进行模拟的一个框架，其方法的基础是对毛发使用 Discrete Elastic Rods 模型，对液体使用粒子元胞（particle-in-cell）模型。在基础上该专题提出了用于处理物体间交互关系的物理和数值模型，建立了用于处理液体在毛发上运动和液体对毛发状态影响的模型。基于毛发间存在的液体的几何关系，专题也建立了一个用于处理相邻毛发由于液体而粘合在一起的情况的模型，并对液体在毛发上滴落的效果进行处理。最终效果可以对湿发抛起、动物甩干毛发、旋转的潮湿的洗车刷以及浸液状态下毛发的粘连现象进行模拟。