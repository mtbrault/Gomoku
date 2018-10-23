#!/usr/bin/env python3
import os, sys

def clean():
	os.system("rm -f src/main.o src/Board.o src/IA.o src/Game.o src/Tile.o pbrain-Zakouille")

def compile():
	os.system("g++  -I./include -Wall -Wextra -Werror -std=c++14  -c -o src/main.o src/main.cpp")
	os.system("g++  -I./include -Wall -Wextra -Werror -std=c++14  -c -o src/Board.o src/Board.cpp")
	os.system("g++  -I./include -Wall -Wextra -Werror -std=c++14  -c -o src/IA.o src/IA.cpp")
	os.system("g++  -I./include -Wall -Wextra -Werror -std=c++14  -c -o src/Game.o src/Game.cpp")
	os.system("g++  -I./include -Wall -Wextra -Werror -std=c++14  -c -o src/Tile.o src/Tile.cpp")
	os.system("g++ src/main.o src/Game.o src/Board.o src/IA.o src/Tile.o -o pbrain-Zakouille -I./include -Wall -Wextra -Werror -std=c++14")

def main():
	if len(sys.argv) == 1:
		compile()
	elif sys.argv[1] == "fclean":
		clean()
	elif sys.argv[1] == "re":
		clean()
		compile()

if __name__ == '__main__':
	main()