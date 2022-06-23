#pragma once

#include "../Layer.h"

class SceneLayer : public Layer
{
	SScene* _scene;
public:
	void SetScene(SScene* scene) { _scene = scene; }
};