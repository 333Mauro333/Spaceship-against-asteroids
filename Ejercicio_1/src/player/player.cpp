#include "player.h"

#include <iostream>

#include "AwesomeLibrary.h"

using std::cout;


Player::Player(int x, int y, int w, int h, unsigned int lives, unsigned int points = 0) : Entity(x, y, w, h)
{
	controls = { 'a', 'd', 'w' }; // Botones izquierda, derecha y disparar, respectivamente.
	sideLimits = { 0, 0 }; // Límites de las paredes, seteados después mediante una función pública.

	this->lives = lives;
	this->points = points;

	setForegroundColor(Color::GREEN);
	cout << "Se ha creado un jugador.\n\n";
	setForegroundColor(Color::WHITE);
}
Player::~Player()
{
	setForegroundColor(Color::RED);
	cout << "El jugador ha sido eliminado de la memoria.\n\n";
	setForegroundColor(Color::WHITE);
}

void Player::update()
{
	if (active)
	{
		shipMovement();
	}
}
void Player::draw()
{
	if (active)
	{
		setForegroundColor(Color::GREEN);
		cout << "  " << static_cast<char>(256 + 30) << "  \n";
		cout << " (" << static_cast<char>(206) << ")\n";
		cout << static_cast<char>(256 + 30) << static_cast<char>(188) << " " << static_cast<char>(200) << static_cast<char>(256 + 30);
		setForegroundColor(Color::WHITE);
	}
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
bool Player::collidesChar(int x, int y, Entity* entity)
{
	return x == entity->getPosition().x && y == entity->getPosition().y;
}

void Player::setBorderLimits(int x, int y)
{
	sideLimits = { x, y };
}

unsigned int Player::getLives()
{
	return lives;
}
unsigned int Player::getPoints()
{
	return points;
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
				move(DIRECTION::LEFT);
			}
		}
		else if (keyPressed == controls.right || keyPressed == static_cast<char>(static_cast<int>(controls.right) - 32))
		{
			if (canMove(DIRECTION::RIGHT))
			{
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
	// Comprueba la actividad de las balas mediante un for y la primera inactiva que encuentre, la dispara.
}
bool Player::isKeyPressed()
{
	return _kbhit();
}
char Player::getCharPressed()
{
	return _getch();
}
