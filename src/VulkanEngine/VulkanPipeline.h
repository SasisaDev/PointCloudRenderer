#pragma once
#include <vector>
#include <string>
#include <vulkan/vulkan.hpp>
#include <fstream>

class VulkanShader
{
protected:
	VkShaderModule vertShaderModule;
	VkShaderModule fragShaderModule;
public:
	VulkanShader(std::string shaderPath);

	void CreateStages();
	VkShaderModule createShaderModule(const std::vector<char>& code);
};

class VulkanPipeline
{
protected:
	VkDevice* device;
	
public:

	VulkanPipeline(VkDevice* Device);

	static std::vector<char> readFile(const std::string& filename);
};