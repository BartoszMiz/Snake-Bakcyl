#include "Board.hpp"

void Board::printBoard() const
{
	std::cout << "\033c";

	for(int i=0; i< HEIGHT ; i++)
	{
		for(int j=0; j< WIDTH ; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

void Board::putSnake(SnakeBody snake)
{
	for(int y=0; y< HEIGHT ; y++)
	{
		for(int x=0; x< WIDTH ; x++)
		{
			if(getCell(Coord(x,y)) == 'o' || getCell(Coord(x,y)) == '@')
			{
				setCell(Coord(x,y), ' ');
			}
		}
	}

	for(auto bodypart : snake)
	{
		setCell(bodypart, 'o');
	}
	setCell(snake.front(), '@');
}

void Board::initializeBoard()
{
	for(int y=0; y< HEIGHT ; y++)
	{
		for(int x=0; x< WIDTH ; x++)
		{
			setCell(Coord(x,y), ' ');
		}
	}
	makeFrame();
}

void Board::makeFrame()
{
	for(int y=0; y<HEIGHT ; y++)
	{
		setCell(Coord(0,y), '#');
		setCell(Coord(WIDTH - 1, y), '#');
	}

	for(int x=0; x<WIDTH ; x++)
	{
		setCell(Coord(x,0), '#');
		setCell(Coord(x, HEIGHT - 1), '#');
	}
}

void Board::setCell(Coord where, char what)
{
	board[where.y][where.x] = what;
}

char Board::getCell(Coord where) const
{
	return board[where.y][where.x];
}

bool Board::isEmpty(Coord where) const
{
	return board[where.y][where.x] == ' ';
}