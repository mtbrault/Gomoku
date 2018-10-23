/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** IA method
*/

#include "IA.hpp"

IA::IA()
	: _size(5)
{
	_checkFive.push_back(std::make_pair(0, 1));
	_checkFive.push_back(std::make_pair(0, -1));
	_checkFive.push_back(std::make_pair(1, 0));
	_checkFive.push_back(std::make_pair(-1, 0));
	_checkFive.push_back(std::make_pair(1, 1));
	_checkFive.push_back(std::make_pair(-1, 1));
	_checkFive.push_back(std::make_pair(1, -1));
	_checkFive.push_back(std::make_pair(-1, -1));
}

IA::~IA()
{
}

int		IA::eval()
{
	int	myRow = maxRow(State::MY);
	int	ennemyRow = maxRow(State::ENNEMY) + 1;

	return myRow - ennemyRow;
}

int	IA::getMaxRow(int x, int y, State state)
{
	int	vecX;
	int	vecY;
	int	counter;
	int	maxCounter = 0;

	for (auto &move : _checkFive) {
		vecX = x;
		vecY = y;
		counter = 0;
		for (int i = 0; i < 4; i++) {
			vecX += move.first;
			vecY += move.second;
			if (vecX < 0 || vecX >= (int)_board.size() || vecY < 0 || vecY >= (int)_board.size())
				break ;
			else if (_board[vecX][vecY] == state)
				counter++;
			else
				break ;
		}
		if (counter > maxCounter)
			maxCounter = counter;
	}
	return maxCounter;
}

int		IA::maxRow(State state)
{
	int	max = 0;
	int	val;

	for (unsigned int y = 0; y < _board.size(); y++) {
		for (unsigned int x = 0; x < _board.size(); x++) {
			if (_board[x][y] == state) {
				val = getMaxRow(x, y, state);
				if (val > max)
					max = val;
			}
		}
	}
	return max;
}

std::pair<int, int>		IA::play(int x, int y, std::vector<std::vector<State> > board)
{
	int	max = -1000000;
	int	val;
	std::vector<std::pair<int, int> >	moveList;
	std::pair<int, int>					tmpMove;

	_board = board;
	moveList = this->fillMove(x, y);
	for (auto &move : moveList) {
		if (_board[move.first][move.second] == State::EMPTY)
			_board[move.first][move.second] = State::MY;
		val = eval();
		if (val > max) {
			max = val;
			tmpMove = move;
		}
		board[move.first][move.second] = State::EMPTY;
	}
	return tmpMove;
}

std::vector<std::pair<int, int> >	IA::fillMove(const int x, const int y)
{
	std::vector<std::pair<int, int> >	move;

	for (unsigned int yi = 0; yi < _board.size(); yi++) {
		for (unsigned int xi = 0; xi < _board.size(); xi++) {
			move.push_back(std::make_pair(yi, xi));
		}
	}
	/*int									boardSize = _board.size() - 1;
	std::vector<std::pair<int, int> >	move;

	for (int i = (_size * -1) + 1; i < _size; i++) {
		if (x - i < 0 || x - i > boardSize || i == 0)
			continue ;
		else if (_board[x - i][y] != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x - i, y));
	}
	for (int i = (_size * -1) + 1; i < _size; i++) {
		if (y - i < 0 || y - i > boardSize || i == 0)
			continue ;
		else if (_board[x][y - i] != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x, y - i));
	}
	for (int i = (_size * -1) + 1; i < _size; i++) {
		if (y - i < 0 || y - i > boardSize || x - i < 0 || x - i > boardSize || i == 0)
			continue ;
		else if (_board[x - i][y - i] != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x - i, y - i));
	}
	for (int i = (_size * - 1) + 1; i < _size; i++) {
		if (y - i < 0 || y - i > boardSize || x + i < 0 || x + i > boardSize || i == 0)
			continue ;
		else if (_board[x + i][y - i] != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x + i, y - i));
	}
	return move;*/
}