#include "entity.h"

#include <iostream>

#include "AwesomeLibrary.h"
#include "general_functions.h"

using std::cout;


Entity::Entity(int x, int y, int w, int h)
{
	active = false;
	position = { x, y };
	size = { w, h };

	showCreationMessage("entidad", false);
}
Entity::~Entity()
{
	showDestructionMessage("entidad", false, 1);
}

Vector2i Entity::getPosition()
{
	return position;
}
Vector2i Entity::getSize()
{
	return size;
}

bool Entity::collidesWith(Entity* entity)
{
	return position.x + size.x - 1 >= entity->position.x && position.x <= entity->position.x + entity->size.x - 1 &&
		   position.y + size.y - 1 >= entity->position.y && position.y <= entity->position.y + entity->size.y - 1 &&
		   active;
}
bool Entity::isActive()
{
	return active;
}
void Entity::setActive(bool active)
{
	this->active = active;
}

void Entity::setPosition(int x, int y)
{
	position = { x, y };
}
