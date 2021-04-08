/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:40:39 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/07 11:59:52 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_data	d;

	va_start(args, str);
	d.ret = 0;
#ifdef DEBUG_TRUE
	D_STR(str);
	BR;
#endif
	while (str && *str)
	{
		// BM("Main");
		d.skip = 0;
		data_init(&d);
		if (*str == '%')
		{
			if ((pars_flag(++str, &d, &args)) == ERR)
				return (ERR);
#ifdef DEBUG_TRUE
	D_INT(data->minus);
	D_INT(data->zero);
	D_INT(data->dot);
	D_INT(data->width);
	D_INT(data->arg);
	D_INT(data->skip);
	D_INT(data->ret);
	D_INT(data->x_up);
	BR;
#endif
		}
		else
		{
			ft_putchar(*str, &d);
			d.skip++;
		}
		while (str && *str && d.skip--)
			str++;
#ifdef DEBUG_TRUE
	D_STR(str);
	BR;
#endif
	}
	va_end(args);
	return (d.ret);
}
