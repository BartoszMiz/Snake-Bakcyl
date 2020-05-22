#include "Coord.hpp"
#include "Board.hpp"

int main()
{
    Board board;

    board.initalaizeBoard();
    board.printBoard();

    typedef std::deque<Coord> Snake;
    SnakeBody snake;
    snake.push_back(Coord(5,6));
    snake.push_back(Coord(5,7));
    snake.push_back(Coord(5,8));

    board.putSnake(snake);
    board.printBoard();
}