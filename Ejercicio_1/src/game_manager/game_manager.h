#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "general_functions.h"
#include "hud/hud.h"
#include "player/player.h"
#include "asteroid/asteroid.h"


class GameManager
{
public:
	GameManager(int top, int bot, int left, int right, bool showDebugMessages = true, int requiredScore = 5000);
	~GameManager();

	void run();

private:
	bool showDebugMessages;

	EDGE_POSITIONS edgePositions;
	int requiredScore;
	bool gameOver;
	bool victory;
	unsigned int counter;

	HUD* hud;
	Player* player;
	static const int asteroidArraySize = 15;
	Asteroid* asteroids[asteroidArraySize];

	void pressAKeyToPlay(bool win);

	void initObjects();
	void update();
	void checkCollisions();
	void draw();

	void resetLevel();

	void appearAsteroids(int stepsToAppear);

	void theGameIsOver(bool victory);
	void showFinalMessage();
};

#endif // !GAME_MANAGER
