#pragma once
#include "../Core/Object.h"
#include "../VulkanEngine/IVulkanRenderable.h"

struct RectTransform
{
	// X and Y of rectangle
	int32_t x, y;
	// Closing X and Y
	// Specify end of rectangle in inversed coordinates
	int32_t cx, cy;
};

enum WidgetAlignRule : uint8_t
{
	ALIGN_TOP = (1u << 0),
	ALIGN_BOTTOM = (1u << 1),
	ALIGN_LEFT = (1u << 2),
	ALIGN_RIGHT = (1u << 3)
};

#define ALIGN_SCREEN ALIGN_TOP | ALIGN_BOTTOM | ALIGN_LEFT | ALIGN_RIGHT
#define ALIGN_VERTICAL ALIGN_TOP | ALIGN_BOTTOM
#define ALIGN

class SWidget : public SObject, public IVulkanRenderable
{
public:


};