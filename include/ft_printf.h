/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:35:54 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/18 16:03:32 by mhadad           ###   ########.fr       */
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

/* --- struct --- */

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
	int	x_maj;
	int	mod;
	int	minus;
	int	zero;
	int	prec;
	int	arg;
}				t_data;

/* --- ft_printf.c --- */

int		ft_printf(const char *str, ...);

/* --- utils1.c --- */

void	ft_putchar(char c);
int		check_arg(const char *str, t_data *data);
void	data_init(t_data *data);

#endif