# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otimofie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 11:59:13 by otimofie          #+#    #+#              #
#    Updated: 2018/05/03 19:23:57 by otimofie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS =  ./srcs/general_functions.c \
		./srcs/ants_check.c \
		./srcs/rooms_validation.c \
		./srcs/rooms_validation_aspects_function.c \
		./srcs/links_check.c \
		./srcs/validation_core.c \
		./srcs/before_building_graph.c \
		./srcs/build_graph_vertex.c \
		./srcs/build_graph_edge.c \
		./srcs/add_data_to_graph.c \
		./srcs/bfs.c \
		./srcs/queue.c \
		./srcs/plan_b.c \
		./srcs/ways_construct.c \
		./srcs/main.c \

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRCS:.c=.o)
	
all: $(NAME)

$(OBJECTS): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	@echo "\033[0;36mCompilation started => [ $(NAME) ]\033[0m"
	@make -C ft_printf
	@gcc $(CFLAGS) -I. $(SRCS) -L ./ft_printf -lftprintf -o $(NAME)
	@echo "\033[93mCompilation finished => [ $(NAME) ]\033[0m"

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C ft_printf
	@echo "\033[0;31mDeleted => [ $(NAME) ]\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) $(LIB)
	@make fclean -C ft_printf
	@echo "\033[0;31mFull Deleted => [ $(NAME) ]\033[0m"

re: fclean all
	@echo "\033[94mRedone => [ $(NAME) ]\033[0m"

.PHONY: all clean fclean re
