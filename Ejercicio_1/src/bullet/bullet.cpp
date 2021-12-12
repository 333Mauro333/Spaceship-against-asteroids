#include "bullet.h"

#include <iostream>

#include "AwesomeLibrary.h"

using std::cout;


Bullet::Bullet(int x, int y, int w, int h) : Entity(x, y, w, h)
{


	setForegroundColor(Color::GREEN);
	cout << "Se ha creado una bala.\n\n";
	setForegroundColor(Color::WHITE);
}
Bullet::~Bullet()
{
	setForegroundColor(Color::RED);
	cout << "La bala ha sido eliminada de la memoria.\n\n";
	setForegroundColor(Color::WHITE);
}

void Bullet::update()
{
	if (active)
	{
		goUp();
	}
}
void Bullet::draw()
{
	if (active)
	{
		clear();
		goToCoordinates(position.x, position.y);
		cout << "ð";
		goToCoordinates(position.x, position.y + 1);
		cout << "ð";
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


void Bullet::goUp()
{
	position.y--;
}
