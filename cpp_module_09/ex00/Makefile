CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRS = main.cpp BitcoinExchange.cpp

NAME =  btc
OBJS = $(SRS:.cpp=.o)
HDRS = BitcoinExchange.hpp

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
