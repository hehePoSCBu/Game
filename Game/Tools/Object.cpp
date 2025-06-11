#include"Object.h"

Entity::Entity()
{
	components = {};
}

bool Entity::addComponent(Component_type type_)
{
	Component* c = new Component(type_);
	if (c == NULL)
	{
		return false;
	}
	this->components.push_back(c);
	return true;
}

Entity::~Entity()
{
}
