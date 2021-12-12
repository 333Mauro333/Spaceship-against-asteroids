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
		// Limpiado de su posición.
		goToCoordinates(position.x, position.y);
		cout << "";
	}
}

void Bullet::hit()
{
	// Se limpia su dibujo.
	active = false;
}


void Bullet::goUp()
{
	position.y--;
}
