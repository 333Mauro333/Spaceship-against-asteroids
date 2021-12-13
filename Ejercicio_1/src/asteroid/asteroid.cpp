#include "asteroid.h"

#include <iostream>

#include "AwesomeLibrary.h"
#include "general_functions.h"

using std::cout;


unsigned int Asteroid::amountOfAsteroids = 0;

Asteroid::Asteroid(int x, int y, int w, int h) : Entity(x, y, w, h)
{
	top = 0;
	bot = 0;
	left = 0;
	right = 0;

	showCreationMessage("asteroide", true, 1);
}
Asteroid::~Asteroid()
{
	if (active)
	{
		amountOfAsteroids--;
	}

	showDestructionMessage("asteroide", true);
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
void Asteroid::setRandomPositionX()
{
	position.x = rand() % (right - left + 1) + left;
	position.y = top + 1;
}

void Asteroid::setLimits(int top, int bot, int left, int right)
{
	this->top = top;
	this->bot = bot;
	this->left = left;
	this->right = right;
}

unsigned int Asteroid::getAmountOfAsteroids()
{
	return amountOfAsteroids;
}


void Asteroid::goDown()
{
	position.y++;
}
