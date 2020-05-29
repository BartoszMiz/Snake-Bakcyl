#include "Snake.hpp"

Snake::Snake(Coord startPosition, Board& board) : _length(1), _board(board)
{
	isAlive = true;
	_body = SnakeBody();
	_body.push_back(startPosition);
}

SnakeBody Snake::getBody() const
{
	return _body;
}

void Snake::move(char input)
{
	Coord newPosition = _body.front();
	input = std::tolower(input);
	switch(input)
	{
	case 'w':
		newPosition.y--;
		break;
	case 's':
		newPosition.y++;
		break;
	case 'a':
		newPosition.x--;
		break;
	case 'd':
		newPosition.x++;
		break;
	default:
		break;
	}

	if(!_board.isWalkable(newPosition))
	{
		isAlive = false;
		return;
	}
	_body.push_front(newPosition);
	if(_board.getCell(newPosition) != 'Q')
	{
		_body.pop_back();
	}
	else
	{
		_board.putApple();
	}
}