#include "entity.h"

#include <iostream>

#include "AwesomeLibrary.h"

using std::cout;


Entity::Entity(int x, int y, int w, int h)
{
	active = false;
	position = { x, y };
	size = { w, h };

	setForegroundColor(Color::GREEN);
	cout << "Se ha creado una entidad.\n";
	setForegroundColor(Color::WHITE);
}
Entity::~Entity()
{
	setForegroundColor(Color::RED);
	cout << "La entidad ha sido eliminada de la memoria.\n\n";
	setForegroundColor(Color::WHITE);
}

Vector2i Entity::getPosition()
{
	return position;
}
bool Entity::collidesWith(Entity* entity)
{
	return position.x + size.x - 1 >= entity->position.x && position.x <= entity->position.x + entity->size.x - 1 &&
		   position.y + size.y - 1 >= entity->position.y && position.y <= entity->position.y + entity->size.y - 1;
}

void Entity::setPosition(int x, int y)
{
	position = { x, y };
}


Vector2i Entity::getSize()
{
	return size;
}

bool Entity::isActive()
{
	return active;
}
void Entity::setActive(bool active)
{
	this->active = active;
}
