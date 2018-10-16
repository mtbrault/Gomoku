/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** Board method
*/

#include "Board.hpp"

Board::Board()
	: _size(-1)
{
}

Board::~Board()
{
}

void	Board::initBoard(int size)
{
	std::vector<State>	tmp;

	_board.clear();
	for (int i = 0; i < size; i++)
		tmp.push_back(State::EMPTY);
	for (int i = 0; i < size; i++)
		_board.push_back(tmp);
	_size = size - 1;
}

bool	Board::isEmpty(int x, int y) const
{
	if (_size == -1 || x > _size || y > _size)
		return false;
	else if (_board[x][y] == State::EMPTY)
		return true;
	return false;	
}

bool	Board::putToken(int x, int y)
{
	if (_size == -1)
		return false;
	else if (_board[x][y] == State::EMPTY)
		_board[x][y] = State::MY;
	return true;
}

bool Board::ennemyPutToken(int x, int y)
{
	if (_size == -1)
		return false;
	else if (_board[x][y] == State::EMPTY)
		_board[x][y] = State::ENNEMY;
	return true;
}