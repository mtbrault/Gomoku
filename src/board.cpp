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
	std::vector<Tile>	tmp;

	_board.clear();
	for (int i = 0; i < size; i++)
		tmp.push_back(Tile());
	for (int i = 0; i < size; i++)
		_board.push_back(tmp);
	_size = size - 1;
}

bool	Board::isEmpty(int x, int y) const
{
	if (_size == -1 || x > _size || y > _size)
		return false;
	else if (_board[x][y].getOwner() == State::EMPTY)
		return true;
	return false;	
}

bool	Board::putToken(int x, int y)
{
	if (_size == -1)
		return false;
	else if (_board[x][y].getOwner() == State::EMPTY)
		_board[x][y].setOwner(State::MY);
	calcScore(x, y, State::MY);
	return true;
}

bool Board::ennemyPutToken(int x, int y)
{
	if (_size == -1)
		return false;
	else if (_board[x][y].getOwner() == State::EMPTY)
		_board[x][y].setOwner(State::ENNEMY);
	calcScore(x, y, State::ENNEMY);
	return true;
}

float	Board::calcLine(int x, int y, State state, std::pair<int, int> dir)
{
	std::array<float, 4>		listVal = {1.75, 1.5, 1.25, 1};
	float						result = 0;
	State						val;

	for (int i = 1; i < 5; i++) {
		if (x + (dir.first * i) < 0 || x + (dir.first * i) > _size || y + (dir.second * i) < 0 || y + (dir.second * i) > _size)
			break ;
		val = _board[x + (dir.first * i)][y + (dir.second * i)].getOwner();
		if (val == state)
			result += listVal[i - 1];
		else if (val != state)
			break ;
	}
	for (int i = 1; i < 5; i++) {
		if (x - (dir.first * i) < 0 || x - (dir.first * i) > _size || y - (dir.second * i) < 0 || y - (dir.second * i) > _size)
			break ;
		val = _board[x - (dir.first * i)][y - (dir.second * i)].getOwner();
		if (val == state)
			result += listVal[i - 1];
		else if (val != state)
			break ;
	}
	return result;
}

void	Board::calcScore(int x, int y, State state)
{
	std::vector<std::pair<int, int> >	listMove = fillMove(x, y);
	std::array<float, 4>				listVal;

	for (auto &move : listMove) {
		if (_board[move.first][move.second].getOwner() == State::EMPTY) {
			listVal[0] = calcLine(move.first, move.second, state, std::make_pair(0, 1));
			listVal[1] = calcLine(move.first, move.second, state, std::make_pair(1, 0));
			listVal[2] = calcLine(move.first, move.second, state, std::make_pair(1, 1));
			listVal[3] = calcLine(move.first, move.second, state, std::make_pair(-1, 1));
			if (state == State::MY)
				_board[move.first][move.second].setMyScore(listVal);
			else if (state == State::ENNEMY)
				_board[move.first][move.second].setEnnemyScore(listVal);
		}
	}
}

std::vector<std::pair<int, int> >	Board::fillMove(const int x, const int y)
{
	int									boardSize = _board.size() - 1;
	std::vector<std::pair<int, int> >	move;

	for (int i = -4; i <= 4; i++) {
		if (x - i < 0 || x - i > boardSize || i == 0)
			continue ;
		else if (_board[x - i][y].getOwner() != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x - i, y));
	}
	for (int i = -4; i <= 4; i++) {
		if (y - i < 0 || y - i > boardSize || i == 0)
			continue ;
		else if (_board[x][y - i].getOwner() != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x, y - i));
	}
	for (int i = -4; i <= 4; i++) {
		if (y - i < 0 || y - i > boardSize || x - i < 0 || x - i > boardSize || i == 0)
			continue ;
		else if (_board[x - i][y - i].getOwner() != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x - i, y - i));
	}
	for (int i = -4; i <= 4; i++) {
		if (y - i < 0 || y - i > boardSize || x + i < 0 || x + i > boardSize || i == 0)
			continue ;
		else if (_board[x + i][y - i].getOwner() != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x + i, y - i));
	}
	return move;
}