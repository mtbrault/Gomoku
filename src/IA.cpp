/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** IA method
*/

#include <stdlib.h>
#include <time.h>	//A SUPPRIMER

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
: _board(std::make_unique<Board>())
{
	_convertSwitch["START"] = 1;
	_convertSwitch["TURN"] = 2;
	_convertSwitch["BEGIN"] = 3;
	_convertSwitch["BOARD"] = 4;
	_convertSwitch["INFO"] = 5;
	_convertSwitch["END"] = 6;
	_convertSwitch["ABOUT"] = 7;
	srand(time(NULL));
}

IA::~IA()
{
}

std::pair<int, int>		IA::play()
{
	int	x = _board->getSize() / 2;
	int	y = _board->getSize() / 2;

	while (!_board->isEmpty(x, y)) {
		x = rand() % _board->getSize() - 1;
		y = rand() % _board->getSize() - 1;
	}
	return std::make_pair(x, y);
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
	std::cout << "OK - everything ok\n";
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
	pos = this->play();
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
