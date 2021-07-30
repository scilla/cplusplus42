SRCS			= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp
OBJ				= $(SRCS:.cpp=.o)

CC				= clang++
RM				= rm -f
CFLAGS			= -std=c++98 -g -Wall -Wextra -Werror # -Wno-shadow -Wshadow
NAME			= animal

%.o:			%.cpp
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
				$(RM) $(OBJ) $(OBJ_BONUS)

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean $(NAME)

g:				fclean $(OBJS)
				$(CC) -g -o $(NAME) ${SRCS} ${LIBS} 

.PHONY:			all clean fclean re g
