#ifndef ASTEROID_H
#define ASTEROID_H

#include "entity/entity.h"


class Asteroid : public Entity
{
public:
	Asteroid();
	~Asteroid();

	void update() override;
	void draw() override;
	void clear() override;

	void appear();
	void hit();

	void setBotLimit(int bot);

private:
	int bot;

	void goDown();
};

#endif // !ASTEROID_H
