#include "game_manager.h"

#include <iostream>

#include "AwesomeLibrary.h"

using std::cout;


GameManager::GameManager(int top, int bot, int left, int right)
{
	const int playerSizeX = 5;
	const int playerSizeY = 3;

	srand(static_cast<unsigned int>(time(NULL)));

	edgePositions = { top, bot, left, right };
	gameOver = false;
	player = new Player((right - left) / 2 + left - playerSizeX / 2, bot - playerSizeY, playerSizeX, playerSizeY, 3);
	player->setActive(true);
	player->setBorderLimits(left, right);
	for (int i = 0; i < Player::getBulletArraySize(); i++)
	{
		player->getBullet(i)->setTopLimit(top);
	}

	hud = new HUD(getScreenWidth() / 16 * 2, getScreenWidth() / 16 * 7, getScreenWidth() / 16 * 12, top - 3);

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

		Sleep(50);
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
	hud->writeStatistics(player);
}
void GameManager::destroy()
{

}