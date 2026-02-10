

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRS = Animal.cpp  main.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
NAME = Animal
OBJS = $(SRS:.cpp=.o)
HDRS = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp

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