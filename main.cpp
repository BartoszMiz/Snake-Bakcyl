#include <iostream>
#include <array>
#include <deque>
#include "Coord.hpp"

typedef std::deque<Coord> SnakeBody;

class Board
{
public:
  static const unsigned BOARD_HEIGHT = 10;
  static const unsigned BOARD_WIDTH = 20;

  typedef std::array<std::array<char , BOARD_WIDTH>, BOARD_HEIGHT> GameBoardArray;

    void printBoard()
    {
        std::cout << "\033c";

        for(int i=0; i< BOARD_HEIGHT ; i++)
        {
            for(int j=0; j< BOARD_WIDTH ; j++)
            {
                std::cout << board[i][j];
            }
            std::cout << std::endl;
        }
    }

    void putSnake(SnakeBody snake)
    {
        for(auto bodypart : snake)
        {
            setCell(bodypart, '0');
        }
        setCell(snake.front(), '@');
    }

    void initalaizeBoard()
    {
        for(int y=0; y< BOARD_HEIGHT ; y++)
        {
            for(int x=0; x< BOARD_WIDTH ; x++)
            {
                setCell(Coord(x,y), ' ');
            }
        }
        makeFrame();
    }
private:
    void makeFrame()
    {
        for(int y=0; y<BOARD_HEIGHT ; y++)
        {
            setCell(Coord(0,y), '#');
            setCell(Coord(BOARD_WIDTH - 1, y), '#');
        }

        for(int x=0; x<BOARD_WIDTH ; x++)
        {
            setCell(Coord(x,0), '#');
            setCell(Coord(x, BOARD_HEIGHT - 1), '#');
        }
    }

    void setCell(Coord where, char what)
    {
        board[where.y][where.x] = what;
    }

    GameBoardArray board;
};


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