# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 21:09:12 by otimofie          #+#    #+#              #
#    Updated: 2018/04/21 16:31:09 by otimofie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
 		ft_wchar_print.c \
 		parsing.c \
 		printing.c \
 		parsing_1.c \
		parsing_2.c \
		parsing_3.c \
		printing_1.c \
		print_simple_string.c \
		print_simple_1.c \
		print_int_1.c \
		print_int_2.c \
		print_int_u_1.c \
		print_int_u_2.c \
		print_w_char_1.c\
		print_w_s_1.c\
		print_w_s_2.c\
		different.c \
		different_1.c \
		different_2.c \
		ft_print_hex_1.c \
		ft_print_hex_2.c \
		print_hex_big_1.c \
		print_hex_big_2.c \
		print_octlal_main_1.c \
		print_octal_main_2.c \
		ft_print_hex_main_pointer_1.c \
		ft_print_hex_main_pointer_2.c \

LIB = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_size_bin.c \
		ft_decimal_length.c \
		ft_print_hex.c \
		ft_hex_length.c \
		ft_print_hex_big.c \
		ft_print_octal.c \
		ft_octal_length.c \
		get_next_line.c \
		ft_isint.c \
		ft_2d_arr_size.c \
		ft_isposint.c \
		ft_str_find_chr.c \

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I libft/

LIBSRCS	= $(addprefix libft/, $(LIB))

OBJECTS = $(SRCS:.c=.o)
LIBOBJ = $(LIBSRCS:.c=.o)

.PHONY: all clean fclean re 

all: $(NAME)

$(OBJECTS): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(LIBOBJ): %.o: %.c
	@gcc -c $(CFLAGS) $(IFLAGS) $< -o $@

$(NAME): $(LIBOBJ) $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS) $(LIBOBJ)

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C ./libft

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
