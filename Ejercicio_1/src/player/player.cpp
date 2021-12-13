#include "player.h"

#include <iostream>

#include "AwesomeLibrary.h"
#include "general_functions.h"

using std::cout;


Player::Player(int x, int y, int w, int h, unsigned int lives, unsigned int points) : Entity(x, y, w, h)
{
	controls = { 'a', 'd', 'w' }; // Botones izquierda, derecha y disparar, respectivamente.
	sideLimits = { 0, 0 }; // Límites de las paredes, seteados después mediante una función pública.

	this->lives = lives;
	this->points = points;

	for (int i = 0; i < bulletArraySize; i++)
	{
		bullets[i] = new Bullet(x + 2, y - 1, 1, 2);
	}

	showCreationMessage("jugador", true, 1);
}
Player::~Player()
{
	for (int i = 0; i < bulletArraySize; i++)
	{
		delete bullets[i];
	}

	showDestructionMessage("jugador", true);
}

void Player::update()
{
	if (active)
	{
		shipMovement();
	}

	for (int i = 0; i < bulletArraySize; i++)
	{
		bullets[i]->update();
	}
}
void Player::draw()
{
	if (active)
	{
		setForegroundColor(Color::GREEN);

		goToCoordinates(position.x + 2, position.y);
		cout << static_cast<char>(256 + 30);
		goToCoordinates(position.x + 1, position.y + 1);
		cout << "(" << static_cast<char>(206) << ")";
		goToCoordinates(position.x, position.y + 2);
		cout << static_cast<char>(256 + 30) << static_cast<char>(188) << " " << static_cast<char>(200) << static_cast<char>(256 + 30);

		setForegroundColor(Color::WHITE);
	}

	for (int i = 0; i < bulletArraySize; i++)
	{
		bullets[i]->draw();
	}
}
void Player::clear()
{
	goToCoordinates(position.x + 2, position.y);
	cout << " ";
	goToCoordinates(position.x + 1, position.y + 1);
	cout << "   ";
	goToCoordinates(position.x, position.y + 2);
	cout << "     ";
}

bool Player::collidesWith(Entity* entity)
{
	return collidesChar(position.x + 2, position.y, entity) || // ▲ (punta).
		   collidesChar(position.x + 1, position.y + 1, entity) || // (
		   collidesChar(position.x + 2, position.y + 1, entity) || // ╬
		   collidesChar(position.x + 3, position.y + 1, entity) || // )
		   collidesChar(position.x, position.y + 2, entity) || // ▲ (borde izquierdo).
		   collidesChar(position.x + 1, position.y + 2, entity) || // ╝
		   collidesChar(position.x + 3, position.y + 2, entity) || // ╚
		   collidesChar(position.x + 4, position.y + 2, entity); // ▲ (borde derecho).
}

void Player::setBorderLimits(int x, int y)
{
	sideLimits = { x, y };
}
void Player::crash()
{
	clear();
	active = false;
}
void Player::addPoints(int points, int maxLimit)
{
	this->points = (this->points + points > maxLimit) ? maxLimit : this->points += points;
}

unsigned int Player::getLives()
{
	return lives;
}
unsigned int Player::getPoints()
{
	return points;
}
int Player::getBulletArraySize()
{
	return bulletArraySize;
}
Bullet* Player::getBullet(int ind)
{
	return bullets[ind];
}


void Player::shipMovement()
{
	char keyPressed = '\0';

	if (isKeyPressed())
	{
		keyPressed = getCharPressed();

		if (keyPressed == controls.left || keyPressed == static_cast<char>(static_cast<int>(controls.left) - 32))
		{
			if (canMove(DIRECTION::LEFT))
			{
				clear();
				move(DIRECTION::LEFT);
			}
		}
		else if (keyPressed == controls.right || keyPressed == static_cast<char>(static_cast<int>(controls.right) - 32))
		{
			if (canMove(DIRECTION::RIGHT))
			{
				clear();
				move(DIRECTION::RIGHT);
			}
		}
		else if (keyPressed == controls.shoot || keyPressed == static_cast<char>(static_cast<int>(controls.shoot) - 32))
		{
			shoot();
		}
	}
}
bool Player::canMove(DIRECTION direction)
{
	switch (direction)
	{
	case DIRECTION::LEFT:
		return position.x - 1 > sideLimits.leftLimit;
		break;

	case DIRECTION::RIGHT:
		return position.x + 1 + size.x - 1 < sideLimits.rightLimit;
		break;
	}

	return false;
}
void Player::move(DIRECTION direction)
{
	switch (direction)
	{
	case DIRECTION::LEFT:
		position.x--;
		break;

	case DIRECTION::RIGHT:
		position.x++;
		break;
	}
}
void Player::shoot()
{
	for (int i = 0; i < bulletArraySize; i++)
	{
		if (!bullets[i]->isActive())
		{
			bullets[i]->setPosition(position.x + 2, position.y - 1);
			bullets[i]->fire();
			break;
		}
	}
}

bool Player::isKeyPressed()
{
	return _kbhit();
}
char Player::getCharPressed()
{
	return _getch();
}

bool Player::collidesChar(int x, int y, Entity* entity)
{
	return x == entity->getPosition().x && y == entity->getPosition().y;
}
