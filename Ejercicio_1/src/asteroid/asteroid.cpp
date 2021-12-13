#include "asteroid.h"

#include <iostream>

#include "AwesomeLibrary.h"
#include "general_functions.h"

using std::cout;


unsigned int Asteroid::amountOfActiveAsteroids = 0;

Asteroid::Asteroid(int x, int y, int w, int h, int pointValue, bool showDebugMessages, int numberToGoDown) : Entity(x, y, w, h, showDebugMessages)
{
	this->showDebugMessages = showDebugMessages;

	this->pointValue = 200;
	this->numberToGoDown = numberToGoDown;
	counter = 0;
	edgePositions = { 0, 0, 0, 0 };

	if (showDebugMessages)
	{
		showCreationMessage("asteroide", true, 1);
	}
}
Asteroid::~Asteroid()
{
	if (active)
	{
		amountOfActiveAsteroids--;
	}

	if (showDebugMessages)
	{
		showDestructionMessage("asteroide", true);
	}
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
	setRandomStepsToDown();
}
void Asteroid::hit()
{
	amountOfActiveAsteroids--;
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
void Asteroid::setMaxSpeed()
{
	if (active)
	{
		counter = 0;
		numberToGoDown = 0;
	}
}
void Asteroid::setRandomStepsToDown()
{
	numberToGoDown = rand() % 5 + 1;
}

int Asteroid::getPointValue()
{
	return pointValue;
}

unsigned int Asteroid::getAmountOfActiveAsteroids()
{
	return amountOfActiveAsteroids;
}


void Asteroid::goDown()
{
	if (counter == numberToGoDown)
	{
		counter = 0;
		position.y++;
	}
	else
	{
		counter++;
	}
}
