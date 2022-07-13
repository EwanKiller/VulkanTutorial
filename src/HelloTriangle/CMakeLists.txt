
add_library(hellotriangle SHARED HelloTriangleApplication.cpp HelloTriangleApplication.h)

target_link_libraries(hellotriangle GLFW vulkan)
