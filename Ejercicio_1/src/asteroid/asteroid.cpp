#include "asteroid.h"

#include <iostream>

#include "AwesomeLibrary.h"
#include "general_functions.h"

using std::cout;


unsigned int Asteroid::amountOfActiveAsteroids = 0;

Asteroid::Asteroid(int x, int y, int w, int h) : Entity(x, y, w, h)
{
	edgePositions = { 0, 0, 0, 0 };

	showCreationMessage("asteroide", true, 1);
}
Asteroid::~Asteroid()
{
	if (active)
	{
		amountOfActiveAsteroids--;
	}

	showDestructionMessage("asteroide", true);
}

void Asteroid::update()
{
	if (active)
	{
		clear();
		goDown();

		if (position.y >= edgePositions.bot)
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
	amountOfActiveAsteroids++;
	active = true;
}
void Asteroid::hit()
{
	amountOfActiveAsteroids--;
	clear();
	active = false;
}
void Asteroid::setRandomPositionX()
{
	position.x = rand() % (edgePositions.right - edgePositions.left + 1) + edgePositions.left;
	position.y = edgePositions.top + 1;
}

void Asteroid::setLimits(int top, int bot, int left, int right)
{
	edgePositions = { top, bot, left, right };
}

unsigned int Asteroid::getAmountOfActiveAsteroids()
{
	return amountOfActiveAsteroids;
}


void Asteroid::goDown()
{
	position.y++;
}
