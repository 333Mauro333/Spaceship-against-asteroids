#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "hud/hud.h"
#include "player/player.h"
#include "asteroid/asteroid.h"


struct EDGE_POSITIONS
{
	int top;
	int bot;
	int left;
	int right;
};

class GameManager
{
public:
	GameManager(int top, int bot, int left, int right);
	~GameManager();

	void run();

private:
	EDGE_POSITIONS edgePositions;
	bool gameOver;
	unsigned int counter;

	HUD* hud;
	Player* player;
	static const int asteroidArraySize = 15;
	Asteroid* asteroids[asteroidArraySize];

	void update();
	void checkCollisions();
	void draw();

	void appearAsteroids(int stepsToAppear);
};

#endif // !GAME_MANAGER
