/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:35:54 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/06 14:11:34 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ======  //TODO REMOVE  ======= */

# include "../include/wraloc.h"
# include "../include/debug_utils.h"
# include <stdio.h>

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

# define FUNC 9

/* --- Null case --- */

# define STR_NULL	"(null)"
# define ADDR_NULL	"0x0"

/* ======  Prototype  ======= */

/* --- typedef --- */

/*
**  `%-` | `min`  | Left align the result within the given field width
**  `%0` | `zero` | Shorter numbers are padded out with leading zeros
**  `%.` | `prec` | How many placesshould be shown after the decimal point
**  `%*` | `arg`  | an int width argument must precede the value that's being
**                   formatted in the argument list, exemple 
**                   `printf("%0*d", 5, 3); ` 00003 is output`
*/

typedef struct s_data
{
	int	minus;
	int	zero;
	int	prec;
	int	width;
	int	arg;
	int	skip;
	int	ret;
	int	x_up;
}				t_data;

/*
**
*/

typedef int	(*t_func_arr)(t_data *data, va_list *args);


/* --- ft_printf.c --- */

int		ft_printf(const char *str, ...);


void	data_init(t_data *data);
int		dummy(t_data *data, va_list *args);
int		left_justify(t_data *data, va_list *args);
int		index_flag(const char *str, t_data *d, va_list *args);
int		check_flag(const char *str, t_data *data, va_list *args);

size_t	len_str(const char *str);
int		len_int(int nbr);
int		len_uint(unsigned int nbr);
void	ft_putstr(const char *s, t_data *data);
void	ft_putchar(char c, t_data *data);
void	putstr_rev(const char *s, t_data *data);
int		print_int(int nbr, t_data *data);
char*	ulongtohex(unsigned long nbr, t_data *data);

int		arg_c(t_data *data, va_list *args);
int		arg_s(t_data *data, va_list *args);
int		arg_d(t_data *data, va_list *args);
int		print_uint(unsigned int nbr, t_data *data);
int		arg_u(t_data *data, va_list *args);
int		arg_p(t_data *data, va_list *args);
int		arg_x(t_data *data, va_list *args);
int		arg_x_up(t_data *data, va_list *args);

int		width(const char *str, t_data *data);
void	width_print(int len, size_t s_len, t_data *data);
#endif