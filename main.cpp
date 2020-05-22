#include <unistd.h>
#include "Coord.hpp"
#include "Board.hpp"
#include "Snake.hpp"

int main()
{
    Board board;
	Coord startPosition(board.WIDTH / 2, board.HEIGHT / 2);
	Snake snake = Snake(startPosition, board);

	while(snake.isAlive)
	{
		board.initalaizeBoard();
		board.putSnake(snake.getBody());
		board.printBoard();
		
		char input = 'w';
		//std::cin >> input;
		snake.Move(input);

		usleep(500000);
	}

	std::cout << "\033c";
	std::cout << "=== GAME OVER ===" << std::endl;
}
