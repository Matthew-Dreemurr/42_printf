/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:40:39 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/26 16:48:16 by mhadad           ###   ########.fr       */
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
	// D_INT(d.min);
	// D_INT(d.zero);
	// D_INT(d.prec);
	// D_INT(d.arg);
	// D_INT(d.skip);
	// D_INT(d.ret);
	// D_STR(str);
	BR;
#endif
		d.skip = 0; // need to remember number of arg to skip
	}
	va_end(args);
	return (d.ret);
}
