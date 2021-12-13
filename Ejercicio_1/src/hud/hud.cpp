#include "hud.h"

#include <iostream>

#include "AwesomeLibrary.h"
#include "general_functions.h"

#include "asteroid/asteroid.h"

using std::cout;


HUD::HUD(int livesX, int pointsX, int amountOfAsteroidsX, int statisticsY, bool showDebugMessages)
{
	this->showDebugMessages = showDebugMessages;

	statPositions = { livesX, pointsX, amountOfAsteroidsX, statisticsY };

	if (showDebugMessages)
	{
		showCreationMessage("HUD", true, 1);
	}
}
HUD::~HUD()
{
	if (showDebugMessages)
	{
		showDestructionMessage("HUD", true, 1);
	}
}

void HUD::writeStatistics(Player* player)
{
	goToCoordinates(statPositions.livesX, statPositions.y);
	cout << "Lives: ";
	for (int i = 0; i < static_cast<int>(player->getLives()); i++)
	{
		cout << static_cast<char>(256 + 3);
	}

	goToCoordinates(statPositions.pointsX, statPositions.y);
	cout << "Points: " << player->getPoints();

	goToCoordinates(statPositions.amountOfAsteroidsX, statPositions.y);
	cout << "Asteroids in screen: " << Asteroid::getAmountOfActiveAsteroids() << " ";
}
void HUD::showEndMessage(bool victory)
{
	victory ? cout << "Felicitaciones! Has alcanzado el puntaje establecido!" : cout << "Los asteroides te han destruido.";
}
