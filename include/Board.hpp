/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** board class
*/

#ifndef BOARD_HPP_
	#define BOARD_HPP_

#include <vector>
#include <iostream>
#include <utility>
#include "Tile.hpp"

class Board
{
public:
	Board();
	~Board();

	void	initBoard(int);
	bool	isEmpty(int, int) const;
	bool	putToken(int, int);
	bool	ennemyPutToken(int, int);
	int		getSize() const {return _size;};
	std::vector<std::vector<Tile> >	getBoard() const {return _board;};

private:
	void								calcScore(int, int, State);
	float								calcLine(int, int, State, std::pair<int, int>);
	std::vector<std::pair<int, int> >	fillMove(const int, const int);
	std::vector<std::vector<Tile> >	_board;
	int								_size;
};

#endif /* !BOARD_HPP_ */
