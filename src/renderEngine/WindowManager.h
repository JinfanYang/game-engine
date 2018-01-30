#ifndef GAMEENGINE_WINDOWMANAGER_H
#define GAMEENGINE_WINDOWMANAGER_H

#include <GLFW/glfw3.h>
#include <iostream>

class WindowManager
{
public:
    WindowManager();
    void createWindow();
    void updateWindow();
    void closeWindow();

    GLFWwindow* window;

private:
    static const int WIDTH = 800;
    static const int HEIGHT = 600;
};


#endif //GAMEENGINE_WINDOWMANAGER_H
