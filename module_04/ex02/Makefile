SRCS	= main.cpp			\
		  Animal.cpp		\
		  Cat.cpp			\
		  Dog.cpp			\
		  Brain.cpp			\

INC		= Animal.hpp		\
		  Cat.hpp			\
		  Dog.hpp			\
		  Brain.hpp			\

OBJS	= $(SRCS:.cpp=.o)

CC		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM		= rm -f

NAME	= animal

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(INC)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) 

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
