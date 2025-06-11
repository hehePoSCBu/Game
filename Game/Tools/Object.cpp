#include"Object.h"

Player::Player()
{
	components = {};
}

bool Player::addComponent(Component_type type_)
{
	Component* c = new Component(type_);
	if (c == NULL)
	{
		return false;
	}
	this->components.push_back(c);
	return true;
}

Player::~Player()
{
}
