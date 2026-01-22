CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRS = PhoneBook.cpp Contact.cpp main.cpp

NAME = phonebook
OBJS = $(SRS:.cpp=.o)
HDRS = PhoneBook.hpp Contact.hpp 

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