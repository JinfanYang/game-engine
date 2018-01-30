#include <renderEngine/WindowManager.h>

int main() {

    WindowManager WM;

    WM.createWindow();

    while(!glfwWindowShouldClose(WM.window)){
        WM.updateWindow();
    }

    WM.closeWindow();

    return 0;
}