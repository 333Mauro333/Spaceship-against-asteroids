#include "AwesomeLibrary.h"

#include "game_manager/game_manager.h"


int main()
{
	GameManager* gameManager = new GameManager(10, getScreenHeight() - 5, 5, getScreenWidth() - 10);

	gameManager->run();

	delete gameManager;


	return 0;
}