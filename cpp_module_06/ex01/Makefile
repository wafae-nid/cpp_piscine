CC = c++
CFLAGS = -Wall -Wextra -Werror 

SRS = main.cpp Serializer.cpp
NAME = Serializer Data.hpp
OBJS = $(SRS:.cpp=.o)
HDRS = Serializer.hpp

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