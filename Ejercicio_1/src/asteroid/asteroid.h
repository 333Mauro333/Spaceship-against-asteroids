#ifndef ASTEROID_H
#define ASTEROID_H

#include "entity/entity.h"


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

	void setVerticalLimits(int top, int bot);

	static unsigned int getAmountOfAsteroids();

private:
	static unsigned int amountOfAsteroids;
	int top;
	int bot;

	void goDown();
};

#endif // !ASTEROID_H
