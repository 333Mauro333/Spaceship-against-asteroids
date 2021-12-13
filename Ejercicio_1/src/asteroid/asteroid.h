#ifndef ASTEROID_H
#define ASTEROID_H

#include "entity/entity.h"
#include "general_functions.h"


class Asteroid : public Entity
{
public:
	Asteroid(int x, int y, int w, int h);
	~Asteroid();

	void update() override;
	void draw() override;
	void clear() override;

	void appear();
	void hit();
	void setRandomPositionX();

	void setLimits(int top, int bot, int left, int right);

	static unsigned int getAmountOfActiveAsteroids();

private:
	static unsigned int amountOfActiveAsteroids;
	EDGE_POSITIONS edgePositions;

	void goDown();
};

#endif // !ASTEROID_H
