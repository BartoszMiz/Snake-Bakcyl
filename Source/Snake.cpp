#include "Snake.hpp"

Snake::Snake(Coord startPosition) : isAlive(true)
{
	body = SnakeBody();
	body.push_back(startPosition);
}

SnakeBody Snake::getBody() const
{
	return body;
}