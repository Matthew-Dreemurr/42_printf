/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:35:54 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/24 12:27:21 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ======  //TODO REMOVE  ======= */

# include "../include/wraloc.h"
# include "../include/debug_utils.h"

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

/* ======  Prototype  ======= */

/* --- Struct --- */

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
	int	min;
	int	zero;
	int	prec;
	int	min_width;
	int	arg;
	int	skip;
	int	ret;
}				t_data;

/* --- ft_printf.c --- */

int		ft_printf(const char *str, ...);

/* --- utils1.c --- */

int	ft_isdigit(int c);
void	ft_putchar(char c, t_data *data);
int		check_flag(const char *str, t_data *data, va_list *args);
void	data_init(t_data *data);

/* --- convert.c --- */

void	decimal();

#endif