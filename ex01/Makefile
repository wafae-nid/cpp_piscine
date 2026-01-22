CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRS = phonebook.cpp

NAME = phonebook
OBJS = $(SRS:.cpp=.o)
HDRS = phonebook.hpp

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