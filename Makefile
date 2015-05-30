# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdannapp <cdannapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/16 21:34:00 by cdannapp          #+#    #+#              #
#    Updated: 2015/05/27 15:44:33 by cdannapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

SRC = ToolBox.cpp
SRC += LineManager.cpp
SRC += Operands/FactoryOperand.cpp
SRC += FileParser.cpp
SRC += Exceptions/OperandException.cpp
SRC += Exceptions/SyntaxeException.cpp
SRC += Exceptions/StackException.cpp
SRC += Exceptions/AssertException.cpp
SRC += Exceptions/FileException.cpp
SRC += main.cpp

HDR = Operands/Operand.tpp

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.cpp=.o)

INCLUDE = -I Operands -I Exceptions -I .

all : $(NAME)

%.o:%.cpp $(HDR)
	clang++ -Wall -Wextra -Werror -c $< -o $@ $(INCLUDE)

$(NAME): $(OBJ)
	clang++ -o $(NAME) $(OBJ) $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
