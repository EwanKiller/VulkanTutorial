cmake_minimum_required(VERSION 3.22)

project(VulkanLearn)

set(CMAKE_CXX_STANDARD 17)

# glfw3
include_directories(/opt/homebrew/Cellar/glfw/3.3.7/include)
link_directories(/opt/homebrew/Cellar/glfw/3.3.7/lib)

# glm
include_directories(/opt/homebrew/Cellar/glm/0.9.9.8/include/glm/include)

# vulkan
link_directories(/Users/ewan/VulkanSDK/1.3.216.0/macOS/lib)
include_directories(/Users/ewan/VulkanSDK/1.3.216.0/macOS/include)

add_subdirectory(src)
