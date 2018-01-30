#include "WindowManager.h"

WindowManager::WindowManager() {
    // Initialize the library
    if (!glfwInit())
    {
        std::cout << "Initialize GLFW failed!" << std::endl;
        return;
    }

    // Activate supersampling
    glfwWindowHint(GLFW_SAMPLES, 8);

    // Ensure to get at least a 3.2 context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    // On apple have to load a core profile with forward compatibility
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

}

void WindowManager::createWindow()
{
    window = glfwCreateWindow(WIDTH, HEIGHT, "Game Engine", NULL, NULL);
    if (!window)
    {
        std::cout << "Window or OpenGL context creation failed!" << std::endl;
        glfwTerminate();
        return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

#ifndef __APPLE__
    glewExperimental = true;
        GLenum err = glewInit();
        if(GLEW_OK != err)
        {
            /* Problem: glewInit failed, something is seriously wrong. */
            fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        }
        glGetError(); // pull and savely ignonre unhandled errors like GL_INVALID_ENUM
        fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
#endif

    glViewport(0, 0, WIDTH, HEIGHT);
}

void WindowManager::updateWindow()
{
    // Swap front and back buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void WindowManager::closeWindow()
{
    glfwTerminate();
}