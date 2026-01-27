CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRS = Weapon.cpp HumanA.cpp main.cpp HumanB.cpp
NAME = VOILENCE
OBJS = $(SRS:.cpp=.o)
HDRS = HumanA.hpp Weapon.hpp HumanB.hpp

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