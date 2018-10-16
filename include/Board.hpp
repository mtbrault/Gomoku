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

private:
	std::vector<std::vector<State> >	_board;
	int									_size;
};

#endif /* !BOARD_HPP_ */
