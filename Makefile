# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otimofie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 11:59:13 by otimofie          #+#    #+#              #
#    Updated: 2018/04/18 11:59:15 by otimofie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

# LIB = filler.a

SRCS = main.c 
		# main_1.c \
		# main_2.c \
		# main_3.c \
		# main_4.c \
		# main_5.c \

HEADER = filler.h

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRCS:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<
	
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./ft_printf
	gcc $(CFLAGS) -I. $(SRCS) -L ./ft_printf -lftprintf -o $(NAME)
	# ar rc $(LIB) $(OBJECTS)
	# ranlib $(LIB)

clean:
	/bin/rm -f $(OBJECTS)
	make clean -C ./ft_printf

fclean: clean
	/bin/rm -f $(NAME) $(LIB)
	make fclean -C ./ft_printf

re: fclean all

