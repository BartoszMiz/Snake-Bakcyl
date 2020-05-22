#pragma once
#include <deque>
#include <locale>
#include "Coord.hpp"
#include "Board.hpp"

typedef std::deque<Coord> SnakeBody;
class Snake
{
private:
	SnakeBody _body;
	unsigned _length;
	Board _board;
public:
	bool isAlive;
	Snake(Coord startPosition, Board& board);
	SnakeBody getBody() const;
	void Move(char input);
};