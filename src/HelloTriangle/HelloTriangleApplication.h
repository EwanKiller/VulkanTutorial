//
// Created by ThisEwan on 2022/6/12.
//

#ifndef VULKANLEARN_HELLOTRIANGLEAPPLICATION_H
#define VULKANLEARN_HELLOTRIANGLEAPPLICATION_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include <optional>
#include <glm/glm.hpp>
#include <array>


namespace Tutorial01 {
    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
    VkResult DestroyDebugUtilsMessengerEXT(VkInstance instance,VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);

    struct QueueFamilyIndices {
        std::optional<uint32_t> graphicsFamily;
        std::optional<uint32_t> presentFamily;

        bool isComplete() {
            return graphicsFamily.has_value() && presentFamily.has_value();
        }
    };
    struct SwapChainSupportDetails {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };
    struct Vertex {
        glm::vec2 pos;
        glm::vec3 color;

        static VkVertexInputBindingDescription getBindingDescription() {
            VkVertexInputBindingDescription bindingDescription{};
            bindingDescription.binding = 0;
            bindingDescription.stride = sizeof(Vertex);
            bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
            return bindingDescription;
        }
        static std::array<VkVertexInputAttributeDescription,2> getAttributeDescriptions() {
            std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions{};
            attributeDescriptions[0].binding = 0;
            attributeDescriptions[0].location = 0;
            attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
            attributeDescriptions[0].offset = offsetof(Vertex,pos);
            attributeDescriptions[1].binding = 0;
            attributeDescriptions[1].location = 1;
            attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
            attributeDescriptions[1].offset = offsetof(Vertex,color);
            return attributeDescriptions;
        }
    };

    class HelloTriangleApplication {
    public:
        void run();
    private:
        GLFWwindow* window;
        VkInstance instance;
        VkDevice device;
        VkQueue graphicsQueue;
        VkDebugUtilsMessengerEXT debugMessenger;
        VkSurfaceKHR surface;
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        VkQueue presentQueue;
        VkSwapchainKHR swapChain;
        std::vector<VkImage> swapChainImages;
        VkFormat swapChainImageFormat;
        VkExtent2D swapChainExtent;
        std::vector<VkImageView> swapChainImageViews;
        VkRenderPass renderPass;
        VkPipelineLayout pipelineLayout;
        VkPipeline graphicsPipeline;
        std::vector<VkFramebuffer> swapChainFramebuffers;
        VkCommandPool commandPool;

        std::vector<VkCommandBuffer> commandBuffers;
        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkFence> inFlightFences;

        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;

        bool framebufferResized = false;

        uint32_t currentFrame = 0;

        void initWindow();
        void initVulkan();
        void createInstance();
        void mainLoop();
        void cleanup();

        const uint32_t WIDTH = 800;
        const uint32_t HEIGHT = 600;
        const char* windowName = "Vulkan Window";
        const uint32_t MAX_FRAMES_IN_FLIGHT = 2;

        // enable validation layer
#ifdef NDEBUG
        const bool enableValidationLayers = false;
#else
        const bool enableValidationLayers = true;
#endif
        const std::vector<const char*> validationLayers = {
                "VK_LAYER_KHRONOS_validation"
        };
        const std::vector<const char*> deviceExtensions = {
                VK_KHR_SWAPCHAIN_EXTENSION_NAME,
                "VK_KHR_portability_subset",
//                VK_KHR_MAINTENANCE1_EXTENSION_NAME
        };
        const std::vector<Vertex> vertices = {
                {{0.0f, -0.5f},{1.0f, 1.0f, 1.0f}},
                {{0.5f,0.5f},{0.0f,1.0f,0.0f}},
                {{-0.5f,0.5f},{0.0f,0.0f,1.0f}}
        };

        static bool checkExtensionsSupport(const std::vector<const char*>& extensions);

        bool checkValidationLayerSupport();

        bool checkDeviceExtensionSupport(VkPhysicalDevice physicalDevice);

        std::vector<const char*> getRequiredExtensions() const;

        static void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

        void setupDebugMessenger();

        static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                            VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

        void pickPhysicalDevice();

        bool isDeviceSuitable(VkPhysicalDevice device);

        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

        void createLogicalDevice();

        void createSurface();

        SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice dv);

        static VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);

        static VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);

        VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

        void createSwapChain();

        void createImageViews();

        static std::vector<char> readFile(const std::string& filename);

        void createRenderPass();

        void createGraphicPipeline();

        VkShaderModule createShaderModule(const std::vector<char>& code);

        void createFramebuffers();

        void createCommandPool();

        void createCommandBuffers();

        void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

        void drawFrame();

        void createSyncObjects();

        void recreateSwapChain();

        void cleanupSwapChain();

        static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

        void createVertexBuffer();

        uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags memoryPropertyFlags);

        void createBuffer(VkDeviceSize size, VkBufferUsageFlags usageFlags,VkMemoryPropertyFlags propertyFlags,VkBuffer& buffer,VkDeviceMemory& deviceMemory);

        void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
    };

} // Tutorial01

#endif //VULKANLEARN_HELLOTRIANGLEAPPLICATION_H
