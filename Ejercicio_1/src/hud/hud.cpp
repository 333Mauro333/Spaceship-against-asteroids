#include "hud.h"

#include <iostream>

#include "AwesomeLibrary.h"

using std::cout;


HUD::HUD(int livesX, int pointsX, int amountOfAsteroidsX, int statisticsY)
{
	statPositions = { livesX, pointsX, amountOfAsteroidsX, statisticsY };

	setForegroundColor(Color::GREEN);
	cout << "Se ha creado un HUD.\n\n";
	setForegroundColor(Color::WHITE);
}
HUD::~HUD()
{
	setForegroundColor(Color::RED);
	cout << "El HUD ha sido eliminado de la memoria.\n\n";
	setForegroundColor(Color::WHITE);
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
