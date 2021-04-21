/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:35:54 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/21 12:01:07 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ======  //TODO REMOVE  ======= */

// # include "../include/wraloc.h"
// # include "../include/debug_utils.h"
// # include <stdio.h>

/* ======  Include  ======= */

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* ======  Macros  ======= */

/* --- Bool macro --- */

# define TRUE		1
# define FALSE		0
# define ERR		-1

/* --- Max & min --- */

# define MAX_INT	2147483647
# define MIN_INT	-2147483648
# define LONG_MAX	9223372036854775807
# define LONG_MIN	-9223372036854775808

/* --- number of function in the arrays of function pointers --- */

# define FLAG_FUNC 5
# define ARG_FUNC 9

/* --- Null case --- */

# define STR_NULL	"(null)"
# define ADDR_NULL	"0x0"

/* ======  Prototype  ======= */

/* --- typedef --- */

/*
**  `%-` | `min`  | Left align the result within the given field width
**  `%0` | `zero` | Shorter numbers are padded out with leading zeros
**  `%.` | `dot` | How many placesshould be shown after the decimal point
**  `%*` | `arg`  | an int width argument must precede the value that's being
**                   formatted in the argument list, exemple 
**                   `printf("%0*d", 5, 3); ` 00003 is output`
*/

typedef	struct s_data
{
	int		minus;
	int		zero;
	size_t	dot;
	int		arg;
	size_t	width;
	size_t	acc;
	int		x_up;
	int		skip;
	int		ret;
}				t_data;

typedef	int	(*t_func_arr)(const char *str, t_data *data, va_list *args);
/*
**
*/

/* *TOREMOVE* */
void	data_debug(t_data *data);




/* ---- src/arg_alpha.c ---- */

int		arg_c(const char *str, t_data *data, va_list *args);
int		arg_s(const char *str, t_data *data, va_list *args);

/* ---- src/arg_hex.c ---- */

int		arg_p(const char *str, t_data *data, va_list *args);
int		arg_x(const char *str, t_data *data, va_list *args);
int		arg_x_up(const char *str, t_data *data, va_list *args);

/* ---- src/arg_num.c ---- */

int		arg_d(const char *str, t_data *data, va_list *args);
int		arg_u(const char *str, t_data *data, va_list *args);

/* ---- src/convert.c ---- */

int		chartoi(const char *str, t_data *data);
char*	ulongtohex(unsigned long nbr, t_data *data);

/* ---- src/dummy.c ---- */

int		dummy_arg(const char *str, t_data *data, va_list *args);
int		dummy_flag(const char *str, t_data *data, va_list *args);

/* ---- src/flag_manager.c ---- */

int		flag_min(const char *str, t_data *data, va_list *args);
int		flag_zero(const char *str, t_data *data, va_list *args);
int		flag_dot(const char *str, t_data *data, va_list *args);
int		flag_arg(const char *str, t_data *data, va_list *args);

/* ---- src/ft_printf.c ---- */

int		ft_printf(const char *str, ...);

/* ---- src/len_utils.c ---- */

size_t	len_str(const char *str);
int		len_int(int nbr);
int		len_uint(unsigned int nbr);

/* ---- src/parser.c ---- */

void	data_init(t_data *data);
int		arg_check(const char *str, t_data *d, va_list *args);
int		flag_check(const char *str, t_data *data, va_list *args);
int		parser(const char *str, t_data *data, va_list *args);

/* ---- src/print_alpha.c ---- */

void	ft_putstr(const char *s, t_data *data);
void	ft_putchar(char c, t_data *data);
void	putstr_rev(const char *s, t_data *data);

/* ---- src/print_manager.c ---- */

void	print_arg_s(const char *str, t_data *data);
void	print_arg_c(const char c, t_data *data);
void	print_arg_x(const char *str, t_data *data);

/* ---- src/print_num.c ---- */

int		print_int(int nbr, t_data *data);
int		print_uint(unsigned int nbr, t_data *data);

/* ---- src/width.c ---- */

void	min_width(size_t str_len, int wdt_len, t_data *data);
void	zero_fill(size_t str_len, t_data *data);
#endif
