#pragma once

#define WIN32_LEAN_AND_MEAN
#define VK_USE_PLATFORM_WIN32_KHR

#include <cstdlib>
#include <string>
#include <vector>
#include <cassert>

#include <vulkan/vulkan.h>

#include "structs.h"

using namespace std;

class DescSet
{
public:
	DescSet();
	~DescSet();

	VkDescriptorSet* data()
	{
		return set.data();
	}

	void setDescPool(VkDescriptorPool pool);
	void CreateDescriptorSet(vector<VkDescriptorSetLayout>& desc_layout, UniformBuffer & uniform_data);	//TEST, UNIFORM ONLY

	void CreateDescriptorSetPassScale(VkDescriptorSetLayout& desc_layout, VkSampler sampler, std::vector<GraphicsImage> inputImageList, VkImageLayout imgLayout);
	void CreateDescriptorSetIA(vector<VkDescriptorSetLayout>& desc_layout, UniformBuffer & uniform_data, VkSampler sampler, VkImageView* views, VkImageLayout imgLayout);

	vector<VkDescriptorSet> set;

	VkDescriptorPool m_descPool;
	VkDevice m_device;

	uint32_t descSetCount = 1;
};

