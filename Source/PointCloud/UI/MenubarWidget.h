#pragma once
#include "../../Core/UI/Widgets/Panel.h"
#include "../../Core/UI/Widgets/Button.h"
#include "../../Core/UI/Widgets/DropMenu.h"
#include "../../Core/Renderer/Mesh/Mesh.h"

class UMenubarWidget : public UPanel
{
public:
	GENERATED_WIDGET_BODY(UMenubarWidget, UPanel)
	{
		WidgetDetails.transform.x = 0;
		WidgetDetails.transform.y = 0;
		WidgetDetails.transform.cx = 1920;
		WidgetDetails.transform.cy = 20;

		brush->SetTint(TColor(0.15, 0.15, 0.15, 1));

		WidgetDetails.alignment.align = ALIGN_LEFT | ALIGN_TOP;
		WidgetDetails.alignment.stretch = STRETCH_HORIZONTAL;

		WidgetCreateInfo dropFile = {};
		dropFile.transform.x = 0;
		dropFile.transform.y = 20;
		dropFile.transform.cx = 120;
		dropFile.transform.cy = 120;
		dropFile.alignment.align = ALIGN_LEFT | ALIGN_TOP;
		dropFile.alignment.stretch = 0;

		UDropMenu* DropFile = CreateWidget(UDropMenu, "DropFile", dropFile);
		AddChild(DropFile);

		WidgetCreateInfo buttonFile = {};
		buttonFile.transform.x = 0;
		buttonFile.transform.y = 0;
		buttonFile.transform.cx = 42;
		buttonFile.transform.cy = 20;
		buttonFile.alignment.align = ALIGN_LEFT | ALIGN_TOP;

		AddChild(CreateWidget(UButton, "File", buttonFile)
			->OnClickCallback([DropFile]() {
				DropFile->SetVisible(!DropFile->bIsVisible);
				}));

		WidgetCreateInfo buttonEdit = {};
		buttonEdit.transform.x = 42;
		buttonEdit.transform.y = 0;
		buttonEdit.transform.cx = 42;
		buttonEdit.transform.cy = 20;
		buttonEdit.alignment.align = ALIGN_LEFT | ALIGN_TOP;

		AddChild(CreateWidget(UButton, "Edit", buttonEdit));
	}
public:
};