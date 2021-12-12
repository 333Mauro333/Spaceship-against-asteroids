#ifndef ENTITY_H
#define ENTITY_H


struct Vector2i
{
	int x;
	int y;
};

class Entity
{
public:
	Entity(int x, int y, int w, int h);
	virtual ~Entity();

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void clear() = 0;

	Vector2i getPosition();
	virtual bool collidesWith(Entity* entity);
	bool isActive();

	void setPosition(int x, int y);

protected:
	bool active;

	Vector2i position;
	Vector2i size;

	Vector2i getSize();

	void setActive(bool active);
};

#endif // !ENTITY_H
