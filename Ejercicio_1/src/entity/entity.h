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
	Entity(int x, int y, int w, int h, bool showDebugMessages = true);
	virtual ~Entity();

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void clear() = 0;

	Vector2i getPosition();
	Vector2i getSize();
	virtual bool collidesWith(Entity* entity);
	bool isActive();
	void setActive(bool active);

	void setPosition(int x, int y);

protected:
	bool showDebugMessages;

	bool active;

	Vector2i position;
	Vector2i size;
};

#endif // !ENTITY_H
