#include "game_manager.h"

#include <iostream>

#include "AwesomeLibrary.h"
#include "general_functions.h"

using std::cout;


GameManager::GameManager(int top, int bot, int left, int right, bool showDebugMessages, int requiredScore)
{
	srand(static_cast<unsigned int>(time(NULL)));
	hideCursor();
	
	edgePositions = { top, bot, left, right };
	this->showDebugMessages = showDebugMessages;
	this->requiredScore = requiredScore;
	gameOver = false;
	victory = false;
	counter = 0;

	initObjects();

	if (showDebugMessages)
	{
		showCreationMessage("controlador del juego", true, 1);

		system("pause");
		clearScreen();
	}
}
GameManager::~GameManager()
{
	delete hud;
	delete player;
	for (int i = 0; i < asteroidArraySize; i++)
	{
		delete asteroids[i];
	}

	if (showDebugMessages)
	{
		showDestructionMessage("controlador del juego", true, 1);
	}
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

	showFinalMessage();
}


void GameManager::pressAKeyToPlay(bool win)
{
	setForegroundColor(Color::LRED);

	goToCoordinates((edgePositions.right - edgePositions.left) / 2 + edgePositions.left - (edgePositions.right / 4), edgePositions.top - 1);
	win ? cout << "Has alcanzado el puntaje requerido! " : cout << "La nave ha sido destruida. ";
	Sleep(1000);
	system("pause");

	setForegroundColor(Color::WHITE);
}

void GameManager::initObjects()
{
	const int playerSizeX = 5;
	const int playerSizeY = 3;

	player = new Player((edgePositions.right - edgePositions.left) / 2 + edgePositions.left - playerSizeX / 2, edgePositions.bot - playerSizeY, playerSizeX, playerSizeY, 3, 0, showDebugMessages);
	player->setActive(true);
	player->setBorderLimits(edgePositions.left, edgePositions.right);
	for (int i = 0; i < Player::getBulletArraySize(); i++)
	{
		player->getBullet(i)->setTopLimit(edgePositions.top);
	}

	hud = new HUD(getScreenWidth() / 16 * 2, getScreenWidth() / 16 * 7, getScreenWidth() / 16 * 12, edgePositions.top - 3, showDebugMessages);

	for (int i = 0; i < asteroidArraySize; i++)
	{
		asteroids[i] = new Asteroid(0, 0, 1, 1, 200, showDebugMessages, rand() % 5 + 1);
		asteroids[i]->setLimits(edgePositions.top, edgePositions.bot, edgePositions.left, edgePositions.right);
	}
}
void GameManager::update()
{
	player->update();

	for (int i = 0; i < asteroidArraySize; i++)
	{
		if (!player->isActive())
		{
			asteroids[i]->setMaxSpeed();
		}

		asteroids[i]->update();
	}

	appearAsteroids(3);

	if (static_cast<int>(player->getPoints()) >= requiredScore)
	{
		pressAKeyToPlay(true);
		theGameIsOver(true);
		return;
	}
	if (!player->isActive() && static_cast<int>(Asteroid::getAmountOfActiveAsteroids()) == 0)
	{
		hud->writeStatistics(player);

		if (static_cast<int>(player->getLives()) > 0)
		{
			pressAKeyToPlay(false);
			resetLevel();
		}
		else
		{
			pressAKeyToPlay(false);
			theGameIsOver(false);
		}
	}
}
void GameManager::checkCollisions()
{
	for (int i = 0; i < asteroidArraySize; i++)
	{
		if (player->collidesWith(asteroids[i]))
		{
			player->crash();
		}

		for (int j = 0; j < player->getBulletArraySize(); j++)
		{
			if (player->getBullet(j)->collidesWith(asteroids[i]))
			{
				player->getBullet(j)->hit();
				player->addPoints(asteroids[i]->getPointValue());
				asteroids[i]->hit();
			}
		}
	}
}
void GameManager::draw()
{
	if (!gameOver)
	{
		setForegroundColor(Color::LRED);
		goToCoordinates(getScreenWidth() / 2 - 15, 3);
		cout << "Puntos requeridos: " << requiredScore << ".";
		setForegroundColor(Color::WHITE);

		hud->writeStatistics(player);
		player->draw();

		for (int i = 0; i < asteroidArraySize; i++)
		{
			asteroids[i]->draw();
		}

		setForegroundColor(Color::BLUE);
		drawFrame(edgePositions.left, edgePositions.top, edgePositions.right, edgePositions.bot);
		setForegroundColor(Color::WHITE);
	}
}

void GameManager::resetLevel()
{
	clearScreen();
	player->subtractALife();
	player->resetPosition();
	player->setActive(true);
}

void GameManager::appearAsteroids(int stepsToAppear)
{
	if (player->isActive())
	{
		if (counter == stepsToAppear)
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
	}
}

void GameManager::theGameIsOver(bool victory)
{
	gameOver = true;

	this->victory = victory;
}
void GameManager::showFinalMessage()
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
