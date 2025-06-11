#include"../App.h"
#include"Components/Component.h"
#include <vector>

class Entity
{
public:
	Entity();
	bool addComponent(Component_type type_);
	~Entity();
private:
	std::vector<Component*> components;
};