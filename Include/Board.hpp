#pragma once
#include "Coord.hpp"
#include <array>
#include <deque>
#include <iostream>

typedef std::deque<Coord> SnakeBody;

class Board
{
public:
	static const unsigned HEIGHT = 10;
	static const unsigned WIDTH = 20;

	typedef std::array<std::array<char , WIDTH>, HEIGHT> GameBoardArray;

	void printBoard() const;
	void putSnake(SnakeBody snake);
	void initializeBoard();
	void putApple();
	bool isEmpty(Coord where) const;
	bool isWalkable(Coord where) const;
	char getCell(Coord where) const;
private:
	void makeFrame();
	void setCell(Coord where, char what);

	GameBoardArray board;
};