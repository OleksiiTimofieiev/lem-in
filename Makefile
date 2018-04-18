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

SRCS = main.c 

HEADER = filler.h

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRCS:.c=.o)

LIB = $()

PRINTF = $(addprefix ft_printf/, $(LIB)) // if smth changed in .c
	
all: $(NAME)

$(OBJECTS): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS) $()
	@make -C ./ft_printf
	@gcc $(CFLAGS) -I. $(SRCS) -L ./ft_printf -lftprintf -o $(NAME)
	@echo "Compiling" [ $(NAME) ]

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C ./ft_printf
	@echo "Deleting" [ $(NAME) ]

fclean: clean
	@/bin/rm -f $(NAME) $(LIB)
	@make fclean -C ./ft_printf
	@echo "Full Deleting" [ $(NAME) ]

re: fclean all
	@echo "Redone" [ $(NAME) ]


.PHONY: all clean fclean re
