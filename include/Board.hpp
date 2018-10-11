/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** board class
*/

#ifndef BOARD_HPP_
	#define BOARD_HPP_

enum State {
	EMPTY,
	MY,
	ENNEMY
};

#include <vector>
#include <iostream>
//#include <memory>

class Board
{
public:
	Board();
	~Board();

	void	initBoard(int);
	bool	isEmpty(int, int) const;
	void	putToken(int, int);
	void	ennemyPutToken(int, int);

private:
	std::vector<std::vector<State> >	_board;
};

#endif /* !BOARD_HPP_ */
