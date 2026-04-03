CC = c++
CFLAGS = -Wall -Wextra -Werror 

SRS = main.cpp Base.cpp Functions.cpp
NAME = Base 
OBJS = $(SRS:.cpp=.o)
HDRS = Base.hpp C.hpp B.hpp A.hpp Functions.hpp

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