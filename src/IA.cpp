/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** IA method
*/

#include "IA.hpp"

IA::IA()
: _board(std::make_unique<Board>())
{
	_board->test();
}

IA::~IA()
{
}

