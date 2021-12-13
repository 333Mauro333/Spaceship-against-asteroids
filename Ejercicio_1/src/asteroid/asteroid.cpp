#include "asteroid.h"

#include <iostream>

#include "AwesomeLibrary.h"

using std::cout;


unsigned int Asteroid::amountOfAsteroids = 0;

Asteroid::Asteroid(int x, int y, int w, int h) : Entity(x, y, w, h)
{
	top = 0;
	bot = 0;

	setForegroundColor(Color::GREEN);
	cout << "Se ha creado un asteroide.\n\n";
	setForegroundColor(Color::WHITE);
}
Asteroid::~Asteroid()
{
	if (active)
	{
		amountOfAsteroids--;
	}

	setForegroundColor(Color::RED);
	cout << "El asteroide ha sido eliminado de la memoria.\n";
	setForegroundColor(Color::WHITE);
}

void Asteroid::update()
{
	if (active)
	{
		clear();
		goDown();

		if (position.y >= bot)
		{
			hit();
		}
	}
}
void Asteroid::draw()
{
	if (active)
	{
		clear();
		goToCoordinates(position.x, position.y);
		cout << static_cast<char>(208);
	}
}
void Asteroid::clear()
{
	goToCoordinates(position.x, position.y);
	cout << " ";
}

void Asteroid::appear()
{
	amountOfAsteroids++;
	active = true;
}
void Asteroid::hit()
{
	amountOfAsteroids--;
	clear();
	active = false;
}

void Asteroid::setVerticalLimits(int top, int bot)
{
	this->top = top;
	this->bot = bot;
}

unsigned int Asteroid::getAmountOfAsteroids()
{
	return amountOfAsteroids;
}


void Asteroid::goDown()
{
	position.y++;
}
