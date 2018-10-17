/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** main file
*/

#include "Game.hpp"

int	main(void)
{
	std::unique_ptr<Game> game = std::make_unique<Game>();

	game->run();
	return 0;
}