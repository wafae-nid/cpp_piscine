CC = c++
CFLAGS = -Wall -Wextra -Werror 

SRS = main.cpp ScalarConverter.cpp Type_Identifers.cpp Type_Converter.cpp
NAME = convert
OBJS = $(SRS:.cpp=.o)
HDRS = ScalarConverter.hpp helpers.hpp

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