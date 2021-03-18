/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:13 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/18 17:24:04 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
**
*/

void	data_init(t_data *data)
{
	data->ret = 0;
	data->c = 0;
	data->s = 0;
	data->p = 0;
	data->d = 0;
	data->i = 0;
	data->u = 0;
	data->x = 0;
	data->x_up = 0;
	data->mod = 0;
	data->min = 0;
	data->zero = 0;
	data->prec = 0;
	data->arg = 0;
	data->skip = 0;
}

/*
**
*/

int	check_arg(const char *str, t_data *data)
{
	if (*str == '%')
	{
		data->ret += write(1, &(*str), 1);
		data->skip++;
	}
	return (TRUE);
}
