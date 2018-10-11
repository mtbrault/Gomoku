/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** main file
*/

#include "Board.hpp"

int	main(int ac, char **av)
{
	(void)ac;(void)av;
	std::unique_ptr<Board>	board = std::make_unique<Board>();

	board->initBoard(20);
	std::cout << board->isEmpty(3, 4) << std::endl;
	board->putToken(3, 4);
	std::cout << board->isEmpty(3, 4) << std::endl;
	return 0;
}