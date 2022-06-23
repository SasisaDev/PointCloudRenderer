#include "LayerStack.h"

void LayerStack::AddLayer(Layer* layer, int index)
{
}

void LayerStack::RenderAll()
{
	for (auto layer : layers)
	{
		layer->Render();
	}
}

void LayerStack::DispatchAll(const Event& e)
{
	for (auto layer : layers)
	{
		layer->OnEvent(e);
	}
}
