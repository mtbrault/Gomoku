/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** IA class
*/

#ifndef IA_HPP_
	#define IA_HPP_

#include "Board.hpp"

class IA {
public:
	IA();
	~IA();

private:
	std::unique_ptr<Board>	_board;
};

#endif /* !IA_HPP_ */
