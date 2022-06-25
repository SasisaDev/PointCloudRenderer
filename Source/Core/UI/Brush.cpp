#include "Brush.h"

SMaterial* SBrush::material = nullptr;

SBrush::SBrush(std::string name)
	: SObject(name)
{
	if (SBrush::material == nullptr)
	{
		material = new SMaterial("BrushMaterial", "Shaders/UI/Brush");
	}
}
