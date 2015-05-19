# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdannapp <cdannapp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/16 21:34:00 by cdannapp          #+#    #+#              #
#    Updated: 2014/03/27 20:34:59 by cdannapp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AbstractVM

SRC =	Operand/FactoryOperand.cpp \
		Operand/OperandInt16.cpp \
		conversion.cpp \
		LineManager.cpp \
		OperandException.cpp \

CFLAGS = -Wall -Werror -Wextra



OBJ = $(SRC:.cpp=.o)

INCLUDE = -I Operands -I Exceptions -I .

all : $(NAME)

%.o:%.cpp
	echo "hello"
	clang++ -Wall -Wextra -Werror -c -o $@ $^ $(INCLUDE)

$(NAME): $(OBJ)
	#echo "hello"
	clang++ -o $(NAME) $(OBJ) $(INCLUDE)

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all


