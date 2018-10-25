/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** IA class
*/

#ifndef IA_HPP_
	#define IA_HPP_

#include <vector>
#include "Board.hpp"

class IA {
public:
	IA();
	~IA();

	std::pair<int, int>					play(std::vector<std::vector<Tile> >);

private:
};

#endif /* !IA_HPP_ */
