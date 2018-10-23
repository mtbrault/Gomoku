/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** Tile method
*/

#include "Tile.hpp"

Tile::Tile()
	: _owner(State::EMPTY), _myScore({0, 0, 0, 0}), _ennemyScore({0, 0, 0, 0})
{
}

Tile::~Tile()
{
}

void	Tile::setOwner(const State owner)
{
	_owner = owner;
}

void	Tile::setMyScore(std::array<float, 4> array)
{
	_myScore = array;
}

void	Tile::setEnnemyScore(std::array<float, 4> array)
{
	_ennemyScore = array;
}

State	Tile::getOwner() const
{
	return _owner;
}

std::array<float, 4>	Tile::getMyScore() const
{
	return _myScore;
}

std::array<float, 4>	Tile::getEnnemyScore() const
{
	return _ennemyScore;
}