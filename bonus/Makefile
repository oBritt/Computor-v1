CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Solver.cpp syntax.cpp utils.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = computor

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re