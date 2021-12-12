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
	return position.x == entity->position.x && position.y == entity->position.y;
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
