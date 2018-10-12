##
## EPITECH PROJECT, 2018
## 301dannon
## File description:
## makefile
##

CXX			=	g++

RM			=	rm -f

RM_W			=	del

SRC			=	src/

SRCS		=		$(SRC)main.cpp		\
				$(SRC)board.cpp		\
				$(SRC)IA.cpp

OBJS		=	$(SRCS:.cpp=.o)

NAME		=	gomoku

CPPFLAGS	= -I./include -Wall -Wextra -Werror -std=c++14

all: $(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:

ifeq ($(OS),Windows_NT)
	$(RM_W) /s *.o *.d *.elf *.map *.log *.exe *# *~
else
	$(RM) $(OBJS)
endif

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
