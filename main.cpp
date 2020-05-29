#include <unistd.h>
#include "Coord.hpp"
#include "Board.hpp"
#include "Snake.hpp"

int main()
{
    Board board;
	board.initializeBoard();
	Coord startPosition(board.WIDTH / 2, board.HEIGHT / 2);
	Snake snake = Snake(startPosition, board);

	while(snake.isAlive)
	{
		board.putSnake(snake.getBody());
		board.printBoard();
		
		char input;
		std::cin >> input;

		input = std::tolower(input);
		if(input == 'e')
		{
			std::cout << "\033c";
			return 0;
		}

		snake.move(input);
	}

	std::cout << "\033c";
	std::cout << "=== GAME OVER ===" << std::endl;
}
