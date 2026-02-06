CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRS =  ClapTrap.cpp main.cpp

NAME = ClapTrap
OBJS = $(SRS:.cpp=.o)
HDRS = ClapTrap.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all