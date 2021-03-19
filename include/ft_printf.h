/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:35:54 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/19 12:45:20 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ======  //TODO REMOVE  ======= */

# include "../include/debug_utils.h"

/* ======  Include  ======= */

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* ======  Macros  ======= */

/*
**   Bool macro.
*/

# define TRUE		1
# define FALSE		0
# define ERR		-1

/*
**   Max & min
*/

# define MAX_INT	2147483647
# define MIN_INT	-2147483648
# define LONG_MAX	9223372036854775807
# define LONG_MIN	-9223372036854775808

/* ======  Prototype  ======= */

/* --- Struct --- */

/*
**  `%c` | `int c`    | Print a singlecharacter
**  `%s` | `int s`    | Print astring of characters
**  `%p` | `int p`    | Print the argument as an address in hexadecimal digits
**  `%d` | `int d`    | Print adecimal (base 10) number
**  `%i` | `int i`    | print aninteger in base 10
**  `%u` | `int u`    | print anunsigned decimal (base 10) number
**  `%x` | `int x`    | Unsigned hexadecimal integer; uses `abcdef`
**  `%X` | `int x_up` | Unsigned hexadecimal integer; uses `ABCDEF`
**  `%%` | `int mod`  | Print `%`
**  `%-` | `int min`  | Left align the result within the given field width
**  `%0` | `int zero` | Shorter numbers are padded out with leading zeros
**  `%.` | `int prec` | How many placesshould be shown after the decimal point
**  `%*` | `int arg`  | an int width argument must precede the value that's being
**   formatted in the argument list, exemple 
**   `printf("%0*d", 5, 3); ` 00003 is output`
*/

typedef struct s_data
{
	int	ret;
	int	c;
	int	s;
	int	p;
	int	d;
	int	i;
	int	u;
	int	x;
	int	x_up;
	int	mod;
	int	min;
	int	zero;
	int	prec;
	int	arg;
	int	skip;
}				t_data;

/* --- ft_printf.c --- */

int		ft_printf(const char *str, ...);

/* --- utils1.c --- */

void	ft_putchar(char c);
int		check_arg(const char *str, t_data *data);
void	data_init(t_data *data);

#endif