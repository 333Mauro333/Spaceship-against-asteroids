#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "player/player.h"

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

	Player* player;

	void update();
	void draw();
	void destroy();

	void checkCollisions();

};

#endif // !GAME_MANAGER
