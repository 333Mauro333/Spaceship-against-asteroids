#ifndef HUD_H
#define HUD_H

#include "player/player.h"


struct STAT_POSITIONS
{
	int livesX;
	int pointsX;
	int amountOfAsteroidsX;
	int y;
};

class HUD
{
public:
	HUD(int livesX, int pointsX, int amountOfAsteroidsX, int statisticsY);
	~HUD();

	void writeStatistics(Player* player);
	void showEndMessage(bool victory);

private:
	STAT_POSITIONS statPositions;
};

#endif // !HUD_H
