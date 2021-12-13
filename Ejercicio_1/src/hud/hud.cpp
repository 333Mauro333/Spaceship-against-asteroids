#include "hud.h"

#include <iostream>

#include "AwesomeLibrary.h"
#include "general_functions.h"

using std::cout;


HUD::HUD(int livesX, int pointsX, int amountOfAsteroidsX, int statisticsY)
{
	statPositions = { livesX, pointsX, amountOfAsteroidsX, statisticsY };

	showCreationMessage("HUD", true, 1);
}
HUD::~HUD()
{
	showDestructionMessage("HUD", true, 1);
}

void HUD::writeStatistics(Player* player)
{
	goToCoordinates(statPositions.livesX, statPositions.y);
	cout << "Lives: ";
	for (int i = 0; i < player->getLives(); i++)
	{
		cout << static_cast<char>(256 + 3);
	}

	goToCoordinates(statPositions.pointsX, statPositions.y);
	cout << "Points: " << player->getPoints();

	goToCoordinates(statPositions.amountOfAsteroidsX, statPositions.y);
	cout << "Asteroids in screen: ";
}
void HUD::showEndMessage(bool victory)
{
	victory ? cout << "Felicitaciones! Has alcanzado el puntaje establecido!" : cout << "Los asteroides te han destruido.";
}
