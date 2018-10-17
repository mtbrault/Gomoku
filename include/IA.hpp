/*
** EPITECH PROJECT, 2018
** gomoku
** File description:
** IA class
*/

#ifndef IA_HPP_
	#define IA_HPP_

#include <unordered_map>
#include <memory>
#include <utility>
#include "Board.hpp"

class IA {
public:
	IA();
	~IA();
	void									run();
	std::pair<int, int>						play(int, int);

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
	std::unordered_map<std::string, int>	_convertSwitch;
	int										_depth;
	int										_actionSize;
};

#endif /* !IA_HPP_ */
