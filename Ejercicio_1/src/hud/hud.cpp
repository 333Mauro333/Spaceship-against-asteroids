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
	setForegroundColor(Color::LRED);

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

	setForegroundColor(Color::WHITE);
}

void HUD::showFinalMessage(Player* player, bool victory, int requiredScore)
{
	setForegroundColor(Color::LRED);

	clearScreen();
	goToCoordinates(getScreenWidth() / 7, 4);
	victory ? cout << "Enhorabuena! Has logrado conseguir los " << requiredScore << " puntos! " : cout << "Los asteroides han destruido tu nave. ";
	if (!player->isActive() && player->getLives() == 0 && static_cast<int>(player->getPoints()) >= requiredScore)
	{
		cout << "\n\nAsi es, a pesar de que la nave fue destruida y te hayas quedado sin vidas, la victoria fue conseguida!\n";
	}
	system("pause");

	clearScreen();

	setForegroundColor(Color::WHITE);
}
