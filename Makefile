# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdannapp <cdannapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/16 21:34:00 by cdannapp          #+#    #+#              #
#    Updated: 2015/05/20 16:33:52 by cdannapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AbstractVM

SRC =	Operands/FactoryOperand.cpp \
		Operands/OperandInt8.cpp \
		Operands/OperandInt16.cpp \
		Operands/OperandInt32.cpp \
		ToolBox.cpp \
		LineManager.cpp \
		Exceptions/OperandException.cpp \
		Exceptions/SyntaxeException.cpp \
		Exceptions/StackException.cpp \
		test.cpp

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.cpp=.o)

INCLUDE = -I Operands -I Exceptions -I .

all : $(NAME)

%.o:%.cpp
	clang++ -Wall -Wextra -Werror -c -o $@ $^ $(INCLUDE)

$(NAME): $(OBJ)
	#echo "hello"
	clang++ -o $(NAME) $(OBJ) $(INCLUDE)

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all
