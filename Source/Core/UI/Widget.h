#pragma once

#include "../Object/Object.h"

#include "../Types/Transform.h"
#include "../Window/Window.h"
#include "../Events/Event.h"

#include <vector>

#define WIDGETSPACE_X 1920
#define WIDGETSPACE_Y 1080

#define GENERATED_WIDGET_BODY(className, Parent) className(std::string name, const WidgetCreateInfo& info) : Parent(name, info)

enum WidgetAlign : uint8_t
{
	ALIGN_TOP		= 0x0,
	ALIGN_BOTTOM	= 0x1,
	ALIGN_LEFT		= 0x2,
	ALIGN_RIGHT		= 0x4
};

enum WidgetStretch : uint8_t
{
	STRETCH_TOP = 0x0,
	STRETCH_BOTTOM = 0x1,
	STRETCH_LEFT = 0x2,
	STRETCH_RIGHT = 0x4
};

typedef struct
{
	Transform2D transform;

	struct {
		WidgetAlign align;
		WidgetStretch stretch;
	} alignment;

} WidgetInfo, WidgetCreateInfo;

class UWidget : public SObject
{
public:
	UWidget(std::string name, const WidgetCreateInfo& info) : SObject(name), WidgetDetails(info) {}
public:
	WidgetInfo WidgetDetails;

	std::vector<UWidget*> Children;

	Transform2D CalculateTransformOnScreenspace();

	virtual void AddChild(UWidget* child);

	void Render();

	virtual void OnPaint();
	virtual void OnEvent(const Event& event) {}
};

template <typename _T>
_T* CreateWidget(std::string name, const WidgetCreateInfo& info)
{
	_T* Widget = new _T(name, info);
	return Widget;
}