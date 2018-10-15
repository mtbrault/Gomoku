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
	void	putToken(int, int);
	void	ennemyPutToken(int, int);
	void test() {std::cout << "Ça marche maggle" << std::endl;};

private:
	std::vector<std::vector<State> >	_board;
};

#endif /* !BOARD_HPP_ */
