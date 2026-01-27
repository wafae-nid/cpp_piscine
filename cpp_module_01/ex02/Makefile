# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 11:42:11 by wnid-hsa          #+#    #+#              #
#    Updated: 2026/01/26 11:43:33 by wnid-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRS = main.cpp

NAME = hi_this_is_brain
OBJS = $(SRS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
