#pragma once

#include <vector>
#include "Layer.h"

class LayerStack
{
protected:
	std::vector<Layer*> layers;
public:

	void AddLayer(Layer* layer, int index = -1);
	template <typename _T>
	_T* GetLayer();

	void RenderAll();
	void DispatchAll(const Event& e);
};

template<typename _T>
_T* LayerStack::GetLayer()
{
	static_assert(std::is_base_of(Layer, _T)::value, "GetLayer should be fed with only layer derived objects");
	if (layers.size() > 0)
	{
		for (Layer* layer : layers)
		{
			if (_T* castedLayer = dynamic_cast<_T*>(layer))
			{
				return castedLayer;
			}
		}
	}
	return nullptr;
}
