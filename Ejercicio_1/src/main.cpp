#include "AwesomeLibrary.h"

#include "game_manager/game_manager.h"


int main()
{
	GameManager* gameManager = new GameManager(5, getScreenHeight() - 1, 5, getScreenWidth() - 5, true);

	gameManager->run();

	delete gameManager;


	return 0;
}