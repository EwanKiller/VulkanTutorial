# Vulkan tutorial
(https://vulkan-tutorial.com/Drawing_a_triangle/Presentation/Swap_chain) #Retrieving the swap chain images
## 踩坑排雷点

### IDE运行报错，找不到`valid validation layer`
- 原因可能是IDE中的环境变量设置有问题，需要指定`VK_LAYER_PATH=/Users/xxx/VulkanSDK/1.x.xxx/macOS/share/vulkan/explicit_layer.d`

### Swapchain
- 创建swapchain的imageUsage可选：
  1. `VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT`  // 直接呈现
  2. `VK_IMAGE_USAGE_TRANSFER_DST_BIT` // 渲染到单独图像
    