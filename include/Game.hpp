/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** Game class
*/

#ifndef Game_HPP_
	#define Game_HPP_

#include <unordered_map>
#include <memory>
#include "IA.hpp"

class Game {
public:
	Game();
	~Game();
	void									run();

private:
	void									start(const std::string &);
	void									turn(const std::string &);
	int										min(std::vector<std::vector<State> >, int);
	std::vector<std::pair<int, int> >		fillMove(const int, const int, const int, const int);
	void									begin();
	void									board();
	void									info(const std::string &, const std::string &);
	void									end();
	void									about();
	std::unique_ptr<Board>					_board;
	std::unique_ptr<IA>						_ia;
	std::unordered_map<std::string, int>	_convertSwitch;
	bool									_end;
};

#endif /* !Game_HPP_ */
