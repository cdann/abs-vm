# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdannapp <cdannapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/16 21:34:00 by cdannapp          #+#    #+#              #
#    Updated: 2015/05/26 16:51:09 by cdannapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AbstractVM

SRC =	ToolBox.cpp \
		LineManager.cpp \
		Operands/FactoryOperand.cpp \
		FileParser.cpp \
		Exceptions/OperandException.cpp \
		Exceptions/SyntaxeException.cpp \
		Exceptions/StackException.cpp \
		Exceptions/AssertException.cpp \
		Exceptions/FileException.cpp \
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
