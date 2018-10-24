/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** IA method
*/

#include "IA.hpp"

IA::IA()
{
}

IA::~IA()
{
}

float	getMax(std::array<float, 4> tab)
{
	float max = tab[0];

	for (int i = 1; i < 4; i++) {
		if (tab[i] > max)
			max = tab[i];
	}
	return max;
}

float	getSecondMax(std::array<float, 4> tab)
{
	int	max = 0;
	int	i;

	for (i = 0; i < 4; i++) {
		if (tab[i] > tab[max])
			max = i;
	}
	tab[i] = 0;
	max = 0;
	for (i = 0; i < 4; i++) {
		if (tab[i] > tab[max])
			max = i;
	}
	return tab[max];
}

std::pair<int, int>		IA::play(std::vector<std::vector<Tile> > board)
{
	std::pair<int, int>		pos;
	std::array<float, 4>	tmp;
	std::array<float, 4>	bestArray = {0, 0, 0, 0};

	for (int x = 0; x < (int)board.size(); x++) {
		for (int y = 0; y < (int)board.size(); y++) {
			if (board[x][y].getOwner() == State::EMPTY) {
				tmp = board[x][y].getMyScore();
				if (getMax(tmp) > getMax(bestArray)) {
					bestArray = tmp;
					pos = std::make_pair(x, y);
				}
				tmp = board[x][y].getEnnemyScore();
				if (getMax(tmp) > getMax(bestArray)) {
					bestArray = tmp;
					pos = std::make_pair(x, y);
				}
				else if (getMax(tmp) == getMax(bestArray)) {
					if (getSecondMax(tmp) > getSecondMax(bestArray)) {
						bestArray = tmp;
						pos = std::make_pair(x, y);
					}
				}
			}
		}
	}
	return pos;
}