/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** Tile class
*/

#ifndef TILE_HPP_
	#define TILE_HPP_

enum State {
	EMPTY,
	MY,
	ENNEMY
};

#include <array>

class Tile {
public:
	Tile();
	~Tile();

	State					getOwner() const;
	void					setOwner(const State);
	std::array<float, 4>	getMyScore() const;
	std::array<float, 4>	getEnnemyScore() const;
	void					setMyScore(std::array<float, 4>);
	void					setEnnemyScore(std::array<float, 4>);

private:
	State					_owner;
	std::array<float, 4>	_myScore;
	std::array<float, 4>	_ennemyScore;
};

#endif /* !TILE_HPP_ */
