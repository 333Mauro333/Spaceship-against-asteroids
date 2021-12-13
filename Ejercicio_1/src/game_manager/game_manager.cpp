#include "game_manager.h"

#include <iostream>

#include "AwesomeLibrary.h"

using std::cout;


GameManager::GameManager(int top, int bot, int left, int right)
{
	const int playerSizeX = 5;
	const int playerSizeY = 3;

	srand(static_cast<unsigned int>(time(NULL)));
	hideCursor();

	edgePositions = { top, bot, left, right };
	gameOver = false;
	counter = 0;

	player = new Player((right - left) / 2 + left - playerSizeX / 2, bot - playerSizeY, playerSizeX, playerSizeY, 3);
	player->setActive(true);
	player->setBorderLimits(left, right);
	for (int i = 0; i < Player::getBulletArraySize(); i++)
	{
		player->getBullet(i)->setTopLimit(top);
	}

	hud = new HUD(getScreenWidth() / 16 * 2, getScreenWidth() / 16 * 7, getScreenWidth() / 16 * 12, top - 3);

	for (int i = 0; i < asteroidArraySize; i++)
	{
		asteroids[i] = new Asteroid(0, 0, 1, 1);
		asteroids[i]->setLimits(top, bot, left, right);
	}

	setForegroundColor(Color::GREEN);
	cout << "Se ha creado un controlador del juego.\n\n";
	setForegroundColor(Color::WHITE);
}
GameManager::~GameManager()
{
	delete hud;
	delete player;
	for (int i = 0; i < asteroidArraySize; i++)
	{
		delete asteroids[i];
	}

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
}


void GameManager::update()
{
	if (counter == 1)
	{
		counter = 0;

		for (int i = 0; i < asteroidArraySize; i++)
		{
			if (!asteroids[i]->isActive())
			{
				asteroids[i]->setRandomPositionX();
				asteroids[i]->appear();
				break;
			}
		}
	}
	else
	{
		counter++;
	}

	player->update();

	for (int i = 0; i < asteroidArraySize; i++)
	{
		asteroids[i]->update();
	}
}
void GameManager::checkCollisions()
{
	for (int i = 0; i < asteroidArraySize; i++)
	{
		if (player->collidesWith(asteroids[i]))
		{
			player->setActive(false);
		}
	}
}
void GameManager::draw()
{
	drawFrame(edgePositions.left, edgePositions.top, edgePositions.right, edgePositions.bot);

	hud->writeStatistics(player);
	player->draw();

	for (int i = 0; i < asteroidArraySize; i++)
	{
		asteroids[i]->draw();
	}
}
