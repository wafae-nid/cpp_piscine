# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 11:01:08 by wnid-hsa          #+#    #+#              #
#    Updated: 2026/01/17 11:18:14 by wnid-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror

SRS = megaphone.cpp

NAME = megaphone
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
