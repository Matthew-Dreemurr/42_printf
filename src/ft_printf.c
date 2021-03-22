/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:40:39 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/22 13:17:03 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_data	d;

	data_init(&d);
	va_start(args, str);
	while (str && *str)
	{
		if (*str != '%')
			d.ret += write(1, &(*str++), 1);
		else
			if (!(check_arg(str++, &d)))
				return (ERR);
		while (str && *str && d.skip)
			str += d.skip--;
		d.skip = 0; // need to remember number of arg to skip
	}
	va_end(args);
	return (d.ret);
}
