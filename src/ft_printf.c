/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:40:39 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/18 15:42:16 by mhadad           ###   ########.fr       */
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
		if (*str != '%')
			d.ret += write(1, &(*str++), 1);
	else if (!(check_arg(str++, &d)))
		return (ERR);
	va_end(args);
	return (d.ret);
}
