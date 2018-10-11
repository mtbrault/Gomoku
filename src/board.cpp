/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** Board method
*/

#include "Board.hpp"

Board::Board()
{
}

Board::~Board()
{
}

void	Board::initBoard(int size)
{
	std::vector<State>	tmp;

	for (int i = 0; i < size; i++)
		tmp.push_back(State::EMPTY);
	for (int i = 0; i < size; i++)
		_board.push_back(tmp);
}

bool	Board::isEmpty(int x, int y) const
{
	if (_board[x][y] == State::EMPTY)
		return true;
	return false;	
}

void	Board::putToken(int x, int y)
{
	if (_board[x][y] == State::EMPTY)
		_board[x][y] = State::MY;
}

void Board::ennemyPutToken(int x, int y)
{
	if (_board[x][y] == State::EMPTY)
		_board[x][y] = State::ENNEMY;
}