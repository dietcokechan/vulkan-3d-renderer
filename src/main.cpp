#include <GLFW/glfw3.h>
#include <iostream>
#include <vulkan/vulkan.h>

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
  
  VkInstance instance;

  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Hello Vulkan!";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pApplicationInfo = &appInfo;

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
  createInfo.enabledExtensionCount = glfwExtensionCount;
  createInfo.ppEnabledExtensionNames = glfwExtensions;
  createInfo.enabledLayerCount = 0;

  if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create Vulkan instance!");
  } else {
    std::cout << "Vulkan instance created successfully!" << std::endl;
  }

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

  vkDestroyInstance(instance, nullptr);
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
