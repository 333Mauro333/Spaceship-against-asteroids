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

	void hit();

private:
	void goUp();
};

#endif // !BULLET_H
