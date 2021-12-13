#ifndef BULLET_H
#define BULLET_H

#include "entity/entity.h"


class Bullet : public Entity
{
public:
	Bullet(int x, int y, int w, int h);
	~Bullet();

	void update() override;
	void draw() override;
	void clear() override;

	void fire();
	void hit();

	bool collidesWith(Entity* entity) override;

	void setTopLimit(int top);

private:
	int top;

	void goUp();

	bool collidesChar(int x, int y, Entity* entity);
};

#endif // !BULLET_H
