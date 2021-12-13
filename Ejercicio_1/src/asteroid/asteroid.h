#ifndef ASTEROID_H
#define ASTEROID_H

#include "entity/entity.h"
#include "general_functions.h"


class Asteroid : public Entity
{
public:
	Asteroid(int x, int y, int w, int h, int pointValue, bool showDebugMessages = true, int numberToGoDown = 1);
	~Asteroid();

	void update() override;
	void draw() override;
	void clear() override;

	void appear();
	void hit();
	void setRandomPositionX();

	void setLimits(int top, int bot, int left, int right);
	void setMaxSpeed();
	void setRandomStepsToDown();

	int getPointValue();

	static unsigned int getAmountOfActiveAsteroids();

private:
	static unsigned int amountOfActiveAsteroids;

	bool showDebugMessages;

	int pointValue;
	int numberToGoDown;
	int counter;
	EDGE_POSITIONS edgePositions;

	void goDown();
};

#endif // !ASTEROID_H
