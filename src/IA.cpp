/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** IA method
*/

#include "IA.hpp"

IA::IA()
	: _depth(2), _size(5)
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
	return 0;
}

bool	IA::fiveRow(int x, int y, State state)
{
	int	vecX;
	int	vecY;
	int	counter;

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
		if (counter == 5)
			return true;
	}
	return false;
}

int		IA::isEnd()
{
	for (unsigned int y = 0; y < _board.size(); y++) {
		for (unsigned int x = 0; x < _board.size(); x++) {
			if (_board[x][y] == State::ENNEMY) {
				if (fiveRow(x, y, State::ENNEMY))
					return 2;
			}
			else if (_board[x][y] == State::MY) {
				if (fiveRow(x, y, State::MY))
					return 1;
			}
		}
	}
	return 0;
}

int		IA::max(int depth, int x, int y)
{
	int	max = -1000000;
	int	val;
	int	end;
	std::vector<std::pair<int, int> >	moveList;

	if ((end = isEnd()) == 1)
		return 1000 - (_depth - depth);
	else if (end == 2)
		return -1000 + (_depth - depth);
	else if (depth == 0)
		return eval();
	moveList = fillMove(x, y);
	for (auto &move : moveList) {
		_board[move.first][move.second] = State::MY;
		val = min(depth - 1, move.first, move.second);
		if (val > max)
			max = val;
		_board[move.first][move.second] = State::EMPTY;
	}
	return max;
}

int		IA::min(int depth, int x, int y)
{
	int		min = 1000000;
	int		val;
	int		end;
	std::vector<std::pair<int, int> >	moveList;

	if ((end = isEnd()) == 1)
		return 1000 - (_depth - depth);
	else if (end == 2)
		return -1000 + (_depth - depth);
	else if (depth == 0)
		return eval();
	moveList = fillMove(x, y);
	for (auto &move : moveList) {
		_board[move.first][move.second] = State::ENNEMY;
		val = max(depth - 1, move.first, move.second);
		if (val < min)
			min = val;
		_board[move.first][move.second] = State::EMPTY;
	}
	return min;;
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
		val = this->min(_depth, move.first, move.second);
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
	int									boardSize = _board.size();
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
	return move;
}