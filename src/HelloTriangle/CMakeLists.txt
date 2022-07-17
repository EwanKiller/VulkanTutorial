
add_library(hellotriangle SHARED HelloTriangleApplication.cpp HelloTriangleApplication.h)

target_link_libraries(hellotriangle GLFW vulkan)

execute_process(COMMAND sh shader.sh WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shaders)