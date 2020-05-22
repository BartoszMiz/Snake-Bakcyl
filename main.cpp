#include <unistd.h>

#include "Coord.hpp"
#include "Board.hpp"
#include "Snake.hpp"

int main()
{
    Board board;
	Coord startPosition(board.WIDTH / 2, board.HEIGHT / 2);
	Snake snake = Snake(startPosition);

	while(true)
	{

		board.initalaizeBoard();
		board.putSnake(snake.getBody());
		board.printBoard();
		usleep(500000);
	}
}
