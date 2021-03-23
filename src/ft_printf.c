/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:40:39 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/23 16:08:01 by mhadad           ###   ########.fr       */
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
		data_init(&d);
		if (*str != '%')
			ft_putchar(*str, &d);
		else
			if (!(check_flag(str, &d, &args)))
				return (ERR);
#ifdef DEBUG_TRUE
	D_INT(d.min);
	D_INT(d.zero);
	D_INT(d.prec);
	D_INT(d.arg);
	D_INT(d.skip);
	D_INT(d.ret);
	D_STR(str);
	BR;
#endif
		while (str && *str && d.skip--)
			str++;
		d.skip = 0; // need to remember number of arg to skip
	}
#ifdef DEBUG_TRUE

#endif
	va_end(args);
	return (d.ret);
}
