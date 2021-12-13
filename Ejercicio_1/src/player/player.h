#ifndef PLAYER_H
#define PLAYER_H

#include "entity/entity.h"
#include "bullet/bullet.h"


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
	Player(int x, int y, int w, int h, unsigned int lives, unsigned int points = 0, bool showDebugMessages = true);
	~Player();

	void update() override;
	void draw() override;
	void clear() override;

	bool collidesWith(Entity* entity) override;

	void setBorderLimits(int x, int y);
	void crash();
	void addPoints(int points, int maxLimit = 10000);
	void addALife();
	void subtractALife();
	void resetPosition();

	unsigned int getLives();
	unsigned int getPoints();
	static int getBulletArraySize();
	Bullet* getBullet(int ind);

private:
	bool showDebugMessages;

	CONTROLS controls;
	SIDE_LIMITS sideLimits;

	static const int bulletArraySize = 2;
	Bullet* bullets[bulletArraySize];

	Vector2i initialPosition;

	unsigned int lives;
	unsigned int points;

	void shipMovement();
	bool canMove(DIRECTION direction);
	void move(DIRECTION direction);
	void shoot();

	bool isKeyPressed();
	char getCharPressed();

	bool collidesChar(int x, int y, Entity* entity);
};

#endif // !PLAYER_H
