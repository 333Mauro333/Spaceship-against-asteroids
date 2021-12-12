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
	~Entity();

	virtual void update() = 0;
	virtual void draw() = 0;

	Vector2i getPosition();
	virtual bool collidesWith(Entity* entity);

protected:
	Vector2i position;

	Vector2i getSize();

private:
	Vector2i size;
};

#endif // !ENTITY_H
