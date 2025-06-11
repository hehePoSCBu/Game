#pragma once

typedef enum Component_type{RenderComponent,AssetComponent,ScriptComponent};

class Component
{
public:
	explicit Component(Component_type type);
	virtual void onEnable();
private:
	Component_type type;
};