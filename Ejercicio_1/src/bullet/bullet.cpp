#include "bullet.h"

#include <iostream>

#include "AwesomeLibrary.h"
#include "general_functions.h"

using std::cout;


Bullet::Bullet(int x, int y, int w, int h) : Entity(x, y, w, h)
{
	top = 0;

	showCreationMessage("bala", false, 1);
}
Bullet::~Bullet()
{
	showDestructionMessage("bala", false);
}

void Bullet::update()
{
	if (active)
	{
		clear();
		goUp();

		if (position.y <= top)
		{
			hit();
		}
	}
}
void Bullet::draw()
{
	if (active)
	{
		clear();
		goToCoordinates(position.x, position.y);
		cout << static_cast<char>(179);
		goToCoordinates(position.x, position.y + 1);
		cout << static_cast<char>(179);
	}
}
void Bullet::clear()
{
	goToCoordinates(position.x, position.y);
	cout << " ";
	goToCoordinates(position.x, position.y + 1);
	cout << " ";
}

void Bullet::fire()
{
	active = true;
}
void Bullet::hit()
{
	clear();
	active = false;
}

bool Bullet::collidesWith(Entity* entity)
{
	return (collidesChar(position.x, position.y, entity) ||
		   collidesChar(position.x, position.y + 1, entity)) &&
		   active && entity->isActive();
}

void Bullet::setTopLimit(int top)
{
	this->top = top;
}


void Bullet::goUp()
{
	position.y--;
}

bool Bullet::collidesChar(int x, int y, Entity* entity)
{
	return x == entity->getPosition().x && y == entity->getPosition().y;
}
