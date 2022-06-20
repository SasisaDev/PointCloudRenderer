#pragma once

#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>

#include <optional>
#include <set>

#include "../Logger/Logger.h"
#include "VulkanPipeline.h"

#pragma comment(lib, "vulkan-1.lib")

class VulkanEngine
{
private:
	const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
	};

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

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

public:
	VkInstance instance; // Vulkan library handle
	VkDebugUtilsMessengerEXT debug_messenger; // Vulkan debug output handle
	VkPhysicalDevice physicalDevice; // GPU chosen as the default device
	VkDevice device; // Vulkan device for commands
	VkSurfaceKHR surface; // Vulkan window surface
	VkSwapchainKHR swapChain;

	std::vector<VkImage> swapChainImages;
	std::vector<VkImageView> swapChainImageViews;
	std::vector<VkFramebuffer> swapChainFramebuffers;

	VkQueue graphicsQueue;
	VkQueue presentQueue;

	VkSurfaceFormatKHR surfaceFormat;
	VkPresentModeKHR presentMode = VK_PRESENT_MODE_FIFO_KHR;
	VkExtent2D extent;

	GLFWwindow* Window;

	VkRenderPass renderPass;
	VulkanPipeline* Pipeline;

	VkCommandPool commandPool;

	VkCommandBuffer commandBuffer;

public:

	VulkanEngine(GLFWwindow* window);
	~VulkanEngine();

	VulkanEngine(const VulkanEngine&) = delete;
	VulkanEngine operator =(const VulkanEngine&) = delete;

	void RecreateSwapChain();
	void CleanupSwapChain();

	void CreateInstance();
	void SetupDebug();
	void PickStartupPhysicalDevice();
	void CreateLogicalDevice();
	void CreateSwapchain();
	void CreateImageViews();
	void CreateGraphicsPipeline();
	void CreateRenderPass();
	void CreateFramebuffers();
	void CreateCommandPool();
	void CreateCommandBuffer();
	
	void SetPhysicalDevice(VkPhysicalDevice device);

	void RecordCmdBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
	void DrawFrame();

	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

	bool isDeviceSuitable(VkPhysicalDevice device);

	bool checkValidationLayerSupport();
};