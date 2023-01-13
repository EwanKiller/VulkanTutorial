cmake_minimum_required(VERSION 3.22)

project(VulkanLearn)

set(CMAKE_CXX_STANDARD 17)

# glfw3
include_directories($ENV{GLFW_INC})
link_directories($ENV{GLFW_LIB})

# glm
include_directories($ENV{GLM_INC})

# vulkan
link_directories($ENV{VULKAN_LIB})
include_directories($ENV{VULKAN_INC})

add_subdirectory(src)
