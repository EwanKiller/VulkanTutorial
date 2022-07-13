#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "HelloTriangle/HelloTriangleApplication.h"

using namespace Tutorial01;

int main() {

    HelloTriangleApplication app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

