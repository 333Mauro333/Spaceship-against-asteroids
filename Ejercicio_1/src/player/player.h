#ifndef PLAYER_H
#define PLAYER_H

#include "entity/entity.h"


enum class DIRECTION { LEFT, RIGHT };

struct CONTROLS
{
	char left;
	char right;
	char shoot;
};
struct SIDE_LIMITS
{
	int leftLimit;
	int rightLimit;
};

class Player : public Entity
{
public:
	Player(int x, int y, int w, int h, unsigned int lives, unsigned int points);
	~Player();

	virtual void update() override;
	virtual void draw() override;

	bool collidesWith(Entity* entity) override;
	bool collidesChar(int x, int y, Entity* entity);

	void setBorderLimits(int x, int y);

	unsigned int getLives();
	unsigned int getPoints();

private:
	CONTROLS controls;
	SIDE_LIMITS sideLimits;

	unsigned int lives;
	unsigned int points;

	void shipMovement();
	bool canMove(DIRECTION direction);
	void move(DIRECTION direction);
	void shoot();

	bool isKeyPressed();
	char getCharPressed();
};

#endif // !PLAYER_H
