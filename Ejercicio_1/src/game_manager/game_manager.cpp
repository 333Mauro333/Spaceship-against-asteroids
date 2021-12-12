#include "game_manager.h"

#include <iostream>

#include "AwesomeLibrary.h"

using std::cout;


GameManager::GameManager(int top, int bot, int left, int right)
{
	const int playerSizeX = 5;
	const int playerSizeY = 3;

	edgePositions = { top, bot, left, right };
	gameOver = false;
	player = new Player((right - left) / 2 + left + playerSizeX / 2, bot - playerSizeY, playerSizeX, playerSizeY, 3);
	player->setActive(true);
	player->setBorderLimits(left, right);

	hideCursor();

	setForegroundColor(Color::GREEN);
	cout << "Se ha creado un controlador del juego.\n\n";
	setForegroundColor(Color::WHITE);
}
GameManager::~GameManager()
{
	setForegroundColor(Color::RED);
	cout << "El controlador del juego ha sido eliminado de la memoria.\n\n";
	setForegroundColor(Color::WHITE);
}

void GameManager::run()
{
	while (!gameOver)
	{
		update();
		checkCollisions();
		draw();
	}

	destroy();
}


void GameManager::update()
{
	player->update();
}
void GameManager::checkCollisions()
{

}
void GameManager::draw()
{
	drawFrame(edgePositions.left, edgePositions.top, edgePositions.right, edgePositions.bot);
	player->draw();
}
void GameManager::destroy()
{

}