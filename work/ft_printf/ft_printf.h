/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:16:35 by otimofie          #+#    #+#             */
/*   Updated: 2018/02/28 13:16:39 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

/*
**-------------------------   types   -------------------------
*/

union				u_t
{
	int				nbr;
	unsigned char	letter;
	wchar_t			ml;
	char			*str;
	wchar_t			*wstr;
	size_t			pul2;
	ssize_t			pul;
};

# define ULLI unsigned long long int

/*
**-------------------------   flags   -------------------------
*/

# define F_Z 1 << 30
# define F_M 1 << 31
# define F_P 1 << 29
# define F_S 1 << 28
# define F_H 1 << 27

/*
**-------------------------   convertors   ---------------------
*/

# define C_SYMBOL 1 << 0
# define C_DECIMAL 1 << 1
# define C_STRING 1 << 2
# define C_MC 1 << 3
# define C_MS 1 << 4
# define C_HEX 1 << 5
# define C_I 1 << 6
# define C_HEXBIG 1 << 7
# define C_OCTAL 1 << 8
# define C_U 1 << 9
# define C_P 1 << 10
# define F_DOT 1 << 11
# define F_PR 1 << 12
# define F_WILD 1 << 14

/*
**-------------------------   colors   -------------------------
*/

# define GREY   "\x1b[90m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

/*
**-------------------------   size modifications   -------------
*/

# define S_L 1 << 20
# define S_J 1 << 21
# define S_H 1 << 22
# define S_Z 1 << 23
# define S_HH 1 << 24
# define S_LL 1 << 25

/*
**-------------------------   main abstract type   -------------
*/

typedef struct		s_p
{
	int				k;
	int				mfw;
	int				pr;
	char			*p;
	union u_t		t;
	int				quantity;
}					t_p;

t_p					g_v;

/*
**--------------------------   valid symbol indications   -------------
*/

enum	e_size_mod
{
	h, l, j, z
};

enum	e_conversions
{
	d, x, i, D, c, s, C, S, X, o, O, u, U, p
};

/*
**--------------------   parsing functions   ---------------------------
*/

void				ft_parsing(va_list ap);

/*
**-----------------------   functions  --------------------------------
*/

int					ft_printf(const char *format, ...);
void				ft_select_printing_conversion(va_list ap);
void				display_bits(int value);
void				ft_wchar_print(unsigned int value);
void				ft_get_flags(va_list ap);
void				ft_set_conversions(void);
void				ft_derivative_conversions(void);
int					ft_check_flags(void);
void				ft_set_flags(void);
void				ft_get_size_mod(void);
void				ft_empty_specifier_handler(void);
void				ft_get_conversions(void);
void				ft_get_min_field_width(void);
void				handle_star(int *i, va_list ap, int tmp);
void				ft_get_precision(va_list ap);
int					ft_check_conversions(void);
int					ft_check_size_mod(void);
void				ft_set_size_mod(void);
void				ft_get_precision(va_list ap);
void				ft_corrections(void);
void				ft_parsing(va_list ap);
int					ft_wide_strlen(wchar_t *s);
int					ft_byte_size(unsigned int value);
int					ft_wide_strlen_bytes(wchar_t *s);
void				ft_wide_s_print(t_p g_v, int chars_to_be_printed);
void				ft_print_simple(void);
void				printer_simple_string(int *s, int *c, char p);
void				ft_putnbr_printf_ss(ssize_t n);
void				ft_print_int(ssize_t g);
void				print_case_1(int s, int z, ssize_t g);
void				print_case_2(int s, int z, ssize_t g);
void				ft_putnbr_printf_s(size_t n);
void				ft_print_int_u(size_t g);
int					ft_decimal_length_u(size_t nbr);
void				case_4_int(int *s, int *d, int *z, ssize_t g);
void				case_3_int(int *s, int *z, ssize_t g);
void				case_2_int(int *s, int *d, int *z, ssize_t g);
void				case_1_int(int *s, int *d, int *z, ssize_t g);
void				ft_print_int_u(size_t g);
void				ft_print_w(t_p g_v);
void				case_1_u(int *s, int *d, int *z, size_t g);
void				case_2_u(int *s, int *d, int *z, size_t g);
void				case_3_u(int *s, int *z);
void				case_4_u(int *s, int *d, int *z, size_t g);
void				ft_print_int_u(size_t g);
void				printer_u(int s, int *i, int z, size_t g);
void				ft_print_w_s(void);
void				print_w_str(int c, int s, char p);
void				ft_megastr_handler(va_list ap);
void				case_1_w(int *s, int *c);
void				case_2_w(int *s, int *c);
void				case_4_w(int *s, int *c);
void				ft_char_handler(int x);
void				ft_mc_handler(int x);
void				ft_str_handler(va_list ap);
void				ft_megastr_handler(va_list ap);
int					ft_decimal_length_u(size_t nbr);
void				ft_print_hex_main(size_t g);
void				ft_print_hex_pr(size_t n, size_t limit);
void				case_1_hex_main(int *s, int *d, int *z, size_t g);
void				case_2_hex_main(int *s, int *d, int *z, size_t g);
void				case_3_hex_main(int *s, int *d, int *z, size_t g);
void				case_4_hex_main(int *s, int *d, int *z, size_t g);
void				case_5_hex_main(void);
void				ft_print_hexbig(size_t g);
void				ft_get_the_var_according_to_a_flag_ss(va_list var);
void				ft_get_the_var_according_to_a_flag_s(va_list var);
void				ft_select_printing_conversion(va_list ap);
void				ft_print_hex_big_2(size_t n, size_t limit);
void				ft_print_octal_main(size_t g);
void				ft_print_hex_main_pointer(size_t g);
void				case_1_hexbig(int *s, int *z, int *d, size_t g);
void				case_2_hexbig(int *s, int *z, int *d, size_t g);
void				case_3_hexbig(int *s, int *z, int *d, size_t g);
void				case_4_hexbig(int *s, int *z, int *d, size_t g);
void				printer_helper_1(void);
void				case_1_octal_main(int *s, int *d, int *z, size_t g);
void				case_2_octal_main(int *s, int *d, int *z, size_t g);
void				case_3_octal_main(int *s, int *d, int *z, size_t g);
void				case_4_octal_main(int *s, int *d, int *z, size_t g);
void				ft_print_octal_main(size_t g);
void				ft_print_hex_main_pointer(size_t g);
void				printer_octal_2(int s, int d, int z, size_t g);
void				case_1_main_printer(int s, int d, int z, size_t g);
void				case_2_main_printer(int s, int d, int z, size_t g);
void				case_3_main_printer(int s, int d, int z, size_t g);
void				case_4_main_printer(int s, int d, int z, size_t g);
void				case_1_pointer(int *s, int *d, int *z, size_t g);
void				case_2_pointer(int *s, int *d, int *z, size_t g);
void				case_3_pointer(int *s, int *d, int *z, size_t g);
void				case_4_pointer(int *s, int *z, size_t g);
void				case_5_pointer(void);
void				printer_octal_2(int s, int d, int z, size_t g);
void				ft_print_octal_2(size_t num, size_t limit);

#endif
