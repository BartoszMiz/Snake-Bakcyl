#pragma once
#include <deque>
#include "Coord.hpp"

typedef std::deque<Coord> SnakeBody;
class Snake
{
private:
	SnakeBody body;
	
public:
	bool isAlive;
	Snake(Coord startPosition);
	SnakeBody getBody() const;
	void Move();
};