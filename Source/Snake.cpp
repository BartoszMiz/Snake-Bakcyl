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

	char checkedCell = _board.getCell(newPosition);
	if(checkedCell == 'o' || checkedCell == '#')
	{
		isAlive = false;
		return;
	}
	_body.push_front(newPosition);
	_body.pop_back();
}