#include <GLFW/glfw3.h>
#include <iostream>

int main() {
  if (!glfwInit()) {
    std::cerr << "Failed to initalize GLFW" << std::endl;
    return -1;
  }
  // no api because I'm using vulkan
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Vulkan!", nullptr, nullptr);
  if (!window) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
