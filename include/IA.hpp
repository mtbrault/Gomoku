/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** IA class
*/

#ifndef IA_HPP_
	#define IA_HPP_

#include <utility>
#include <vector>
#include "Board.hpp"

class IA {
public:
	IA();
	~IA();

	std::pair<int, int>					play(int, int, std::vector<std::vector<State> >);

private:
	int									eval();
	bool								checkPosition(int, int, std::pair<int, int>, State);
	int									getMaxRow(int, int, State);
	int									maxRow(State);
	std::vector<std::pair<int, int> >	fillMove(const int, const int);
	int									_size;
	std::vector<std::vector<State> >	_board;
	std::vector<std::pair<int, int> >	_checkFive;
};

#endif /* !IA_HPP_ */
