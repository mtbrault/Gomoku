/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** IA method
*/

#include <limits>
#include "IA.hpp"

static std::vector<std::string>	parsLine(const std::string &line, const std::string &delim)
{
	std::vector<std::string>	val;
	auto						start = 0;
	auto						end = line.find(delim);
	while ("Infinite loop") {
		val.push_back(line.substr(start, end - start));
		if (end == std::string::npos)
			break ;
		start = end + 1;
		end = line.find(' ', start);
	}
	return val;
}

IA::IA()
: _board(std::make_unique<Board>()), _depth(2), _actionSize(5)
{
	_convertSwitch["START"] = 1;
	_convertSwitch["TURN"] = 2;
	_convertSwitch["BEGIN"] = 3;
	_convertSwitch["BOARD"] = 4;
	_convertSwitch["INFO"] = 5;
	_convertSwitch["END"] = 6;
	_convertSwitch["ABOUT"] = 7;
}

IA::~IA()
{
}

int		IA::min(std::vector<std::vector<State> > board, int depth)
{
	(void)board; (void)depth;
	return 0;
}

std::pair<int, int>		IA::play(int x, int y)
{
	int	max = -INFINITY;
	int	val;
	std::vector<std::vector<State> >	board = _board->getBoard();
	std::vector<std::pair<int, int> >	moveList;
	std::pair<int, int>					tmpMove;

	moveList = this->fillMove(x, y, _actionSize, _board->getSize());
	for (auto &move : moveList) {
		if (board[move.first][move.second] == State::EMPTY)
			board[move.first][move.second] = State::MY;
		val = this->min(board, _depth);
		if (val > max) {
			max = val;
			tmpMove = move;
		}
		board[move.first][move.second] = State::EMPTY;
	}
	return tmpMove;
}

void	IA::start(const std::string &cmd)
{
	int	size;

	try {
		size = std::stoi(cmd);
	} catch (std::exception &ex) {
		std::cout << "ERROR " << ex.what() << std::endl;
		return ;
	}
	_board->initBoard(size);
	std::cout << "OK\n";
}

void	IA::turn(const std::string &cmd)
{
	std::vector<std::string>	vec = parsLine(cmd, ",");
	std::pair<int, int>			pos;
	int							x;
	int							y;

	try {
		x = std::stoi(vec[0]);
		y = std::stoi(vec[1]);
	} catch (std::exception &ex) {
		std::cout << "ERROR " << ex.what() << std::endl;
		return ;
	}
	if (!_board->ennemyPutToken(x, y)) {
		std::cout << "ERROR empty board\n";
		return ;
	}
	pos = this->play(x, y);
	if (!_board->putToken(pos.first, pos.second))
		std::cout << "ERROR empty board\n";
	std::cout << pos.first << "," << pos.second << std::endl;
}

void	IA::begin()
{
	int	size = _board->getSize();

	std::cout << size / 2 << "," << size / 2 << std::endl;
	if (!_board->putToken(size / 2, size / 2))
		std::cout << "ERROR empty board\n";
}

void	IA::board()
{
}

void	IA::info(const std::string &, const std::string &)
{
}

void	IA::end()
{
}

void	IA::about()
{
}

void	IA::run()
{
	std::string					line;
	std::vector<std::string>	cmd;

	while ("Bouclinf") {
		line.clear();
		getline(std::cin, line);
		cmd = parsLine(line, " ");
		switch (_convertSwitch[cmd[0]]) {
			case 1 : this->start(cmd[1]); break;
			case 2 : this->turn(cmd[1]); break;
			case 3 : this->begin(); break;
			case 4 : this->board(); break;
			case 5 : this->info(cmd[1], cmd[2]); break;
			case 6 : this->end(); break;
			case 7 : this->about(); break;
			default : std::cout << "UNKNOW This command doesn't exist\n";
		}
	}
}

std::vector<std::pair<int, int> >	IA::fillMove(const int x, const int y, const int size, const int boardSize)
{
	std::vector<std::pair<int, int> > move;

	for (int i = (size * -1) + 1; i < size; i++) {
		if (x - i < 0 || x - i > boardSize || i == 0)
			continue ;
		else if (_board->getBoard()[x - i][y] != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x - i, y));
	}
	for (int i = (size * -1) + 1; i < size; i++) {
		if (y - i < 0 || y - i > boardSize || i == 0)
			continue ;
		else if (_board->getBoard()[x][y - i] != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x, y - i));
	}
	for (int i = (size * -1) + 1; i < size; i++) {
		if (y - i < 0 || y - i > boardSize || x - i < 0 || x - i > boardSize || i == 0)
			continue ;
		else if (_board->getBoard()[x - i][y - i] != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x - i, y - i));
	}
	for (int i = (size * - 1) + 1; i < size; i++) {
		if (y - i < 0 || y - i > boardSize || x + i < 0 || x + i > boardSize || i == 0)
			continue ;
		else if (_board->getBoard()[x + i][y - i] != State::EMPTY)
			continue ;
		move.push_back(std::make_pair(x + i, y - i));
	}
	return move;
}