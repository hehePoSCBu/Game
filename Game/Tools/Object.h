#include"../App.h"
#include"Components/Component.h"
#include <vector>

class Player
{
public:
	Player();
	bool addComponent(Component_type type_);
	~Player();
private:
	std::vector<Component*> components;
};