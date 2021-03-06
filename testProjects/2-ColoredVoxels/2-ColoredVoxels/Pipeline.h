#pragma once

#define WIN32_LEAN_AND_MEAN
#define VK_USE_PLATFORM_WIN32_KHR

#include <cstdlib>
#include <string>
#include <vector>
#include <cassert>

#include <vulkan/vulkan.h>

#include "SPIRV/GlslangToSpv.h"

#include "structs.h"

using namespace std;

class Pipeline
{
public:
	Pipeline();
	~Pipeline();

	void initPipeline(
		VkVertexInputBindingDescription & vi_binding, VkVertexInputAttributeDescription * vi_attribs, 
		VkPipelineLayout pipeline_layout, VkPipelineShaderStageCreateInfo * shaderStages, VkRenderPass render_pass,
		int attachmentCount, int subpass);

	void initPipelineForUnit(
		VkVertexInputBindingDescription & vi_binding, VkVertexInputAttributeDescription * vi_attribs,
		VkPipelineLayout pipeline_layout, VkPipelineShaderStageCreateInfo * shaderStages, VkRenderPass render_pass,
		int outputCount, bool useDepth = false);

	void createPipeline();

	void InitShader(const char * vertShaderText, const char * fragShaderText);

	void initResources(TBuiltInResource & Resources);
	EShLanguage FindLanguage(const VkShaderStageFlagBits shader_type);
	bool GLSLtoSPV(const VkShaderStageFlagBits shader_type, const char * pshader, std::vector<unsigned int>& spirv);

	VkGraphicsPipelineCreateInfo pipelineInfo;

	VkPipeline pipelineObj;
	VkPipelineCache cache;
	VkPipelineShaderStageCreateInfo info[2];
	VkPipelineCacheCreateInfo pipelineCachei;
	VkDynamicState dynamicStateEnables[VK_DYNAMIC_STATE_RANGE_SIZE];
	VkPipelineDynamicStateCreateInfo dynamicState = {};
	VkPipelineVertexInputStateCreateInfo vi;
	VkPipelineInputAssemblyStateCreateInfo ia;
	VkPipelineRasterizationStateCreateInfo rs;
	VkPipelineColorBlendStateCreateInfo cb;
	VkPipelineColorBlendAttachmentState att_state[10];
	VkPipelineViewportStateCreateInfo vp = {};
	VkPipelineDepthStencilStateCreateInfo ds;
	VkPipelineMultisampleStateCreateInfo ms;

	VkDevice m_device;
};

