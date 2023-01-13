# Vulkan tutorial
(https://vulkan-tutorial.com/Overview) 

## 项目环境配置
- 在环境变量中配置以下：
```shell
# Vulkan SDK
export VULKAN_SDK=/Users/ewan/VulkanSDK/1.3.216.0/macOS
export VULKAN_LIB=/Users/ewan/VulkanSDK/1.3.216.0/macOS/lib
export VULKAN_INC=/Users/ewan/VulkanSDK/1.3.216.0/macOS/include
export VK_ICD_FILENAMES=$VULKAN_SDK/share/vulkan/icd.d/MoltenVK_icd.json
export VK_LAYER_PATH=$VULKAN_SDK/share/vulkan/explicit_layer.d

# glfw3
export GLFW_LIB=/usr/local/Cellar/glfw/3.3.8/lib
export GLFW_INC=/usr/local/Cellar/glfw/3.3.8/include

# glm header-only
export GLM_INC=/usr/local/Cellar/glm/0.9.9.8/include
```

## 踩坑排雷点

### IDE运行报错，找不到`valid validation layer`
- 原因可能是IDE中的环境变量设置有问题，需要指定`VK_LAYER_PATH=/Users/xxx/VulkanSDK/1.x.xxx/macOS/share/vulkan/explicit_layer.d`

### Swapchain
- 创建Swapchain的imageUsage可选：
  1. `VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT`  // 直接呈现
  2. `VK_IMAGE_USAGE_TRANSFER_DST_BIT` // 渲染到单独图像
    