##
## EPITECH PROJECT, 2018
## 301dannon
## File description:
## makefile
##

CXX			=	g++

RM			=	rm -f

SRC			=	src/

SRCS		=	$(SRC)main.cpp		\
				$(SRC)board.cpp		\
				$(SRC)IA.cpp

OBJS		=	$(SRCS:.cpp=.o)

NAME		=	test

CPPFLAGS	= -I./include -Wall -Wextra -Werror -std=c++14

all: $(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re