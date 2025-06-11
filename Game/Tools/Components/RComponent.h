#pragma once
#include"Component.h"
#include"../../App.h"

class RComponent :public Component
{
private:
	Model* model;
	Shader* shader;
public:
	void init(string model,Shader* shader);
	void onEnable() override;
};