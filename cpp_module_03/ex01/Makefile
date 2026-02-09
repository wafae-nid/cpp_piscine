CC = c++
CFLAGS = -Wall -Wextra -Werror

SRS =  ClapTrap.cpp ScavTrap.cpp main.cpp

NAME = ScavTrap
OBJS = $(SRS:.cpp=.o)
HDRS = ClapTrap.hpp ScavTrap.hpp

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