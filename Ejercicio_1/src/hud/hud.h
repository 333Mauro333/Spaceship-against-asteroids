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
	HUD(int livesX, int pointsX, int amountOfAsteroidsX, int statisticsY, bool showDebugMessages = true);
	~HUD();

	void writeStatistics(Player* player);
	void showFinalMessage(Player* player, bool victory, int requiredScore);

private:
	bool showDebugMessages;

	STAT_POSITIONS statPositions;
};

#endif // !HUD_H
