#!/usr/bin/env python3
import os, sys

def clean():
	os.system("rm -f src/main.o src/board.o src/IA.o pbrain-test")

def compile():
	os.system("g++  -I./include -Wall -Wextra -Werror -std=c++14  -c -o src/main.o src/main.cpp")
	os.system("g++  -I./include -Wall -Wextra -Werror -std=c++14  -c -o src/board.o src/board.cpp")
	os.system("g++  -I./include -Wall -Wextra -Werror -std=c++14  -c -o src/IA.o src/IA.cpp")
	os.system("g++ src/main.o src/board.o src/IA.o -o pbrain-test -I./include -Wall -Wextra -Werror -std=c++14")

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