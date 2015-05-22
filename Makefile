# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdannapp <cdannapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/16 21:34:00 by cdannapp          #+#    #+#              #
#    Updated: 2015/05/22 16:08:40 by cdannapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AbstractVM

SRC =	Operands/FactoryOperand.cpp \
		ToolBox.cpp \
		LineManager.cpp \
		FileParser.cpp \
		Exceptions/OperandException.cpp \
		Exceptions/SyntaxeException.cpp \
		Exceptions/StackException.cpp \
		Exceptions/AssertException.cpp \
		test.cpp

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.cpp=.o)

INCLUDE = -I Operands -I Exceptions -I .

all : $(NAME)

%.o:%.cpp
	clang++ -Wall -Wextra -Werror -c -o $@ $^ $(INCLUDE)

$(NAME): $(OBJ)
	clang++ -o $(NAME) $(OBJ) $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
