/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:40:39 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/02 16:37:33 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_data	d;

	va_start(args, str);
	d.ret = 0;
	while (str && *str)
	{
		d.skip = 0;
		data_init(&d);
		if (*str != '%')
		{
			ft_putchar(*str, &d);
			d.skip++;
		}
		else
			if ((check_flag(++str, &d, &args)) == ERR)
				return (ERR);
		while (str && *str && d.skip--)
			str++;
#ifdef DEBUG_TRUE
	D_INT(d.minus);
	D_INT(d.zero);
	D_INT(d.prec);
	D_INT(d.arg);
	D_INT(d.skip);
	D_INT(d.ret);
	D_STR(str);
	BR;
#endif
	}
	va_end(args);
	return (d.ret);
}
