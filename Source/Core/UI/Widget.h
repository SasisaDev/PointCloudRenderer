#pragma once

#include "../Object/Object.h"

#include "../Types/Transform.h"
#include "../Window/Window.h"
#include "../Events/Event.h"
#include "../Renderer/Mesh/Mesh.h"
#include "Brush.h"

#include <vector>

#define WIDGETSPACE_X 1920
#define WIDGETSPACE_Y 1080

#define GENERATED_WIDGET_BODY(className, Parent, ...) className(std::string name, const WidgetCreateInfo& info, __VA_ARGS__) : Parent(name, info)

enum WidgetAlign : uint8_t
{
	ALIGN_TOP		= 0x0,
	ALIGN_BOTTOM	= 0x1,
	ALIGN_LEFT		= 0x2,
	ALIGN_RIGHT		= 0x4
};

enum WidgetStretch : uint8_t
{
	STRETCH_VERTICAL = 0x0,
	STRETCH_HORIZONTAL = 0x1,
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

	virtual void Update(float DeltaTime);

	virtual void OnPaint();
	virtual bool OnEvent(const Event& event) { return false; }

	void DrawBrush(Mesh* mesh, SBrush* brush);
};

template <typename _T>
_T* CreateWidget(std::string name, const WidgetCreateInfo& info)
{
	_T* Widget = new _T(name, info);
	return Widget;
}

#define CreateWidget(_class, name, info, ...) new _class (name, info, __VA_ARGS__)