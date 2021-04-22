/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:40:39 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/22 16:34:29 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*        Debug         */

#ifdef DEBUG_TRUE
void	data_debug(t_data *data)
{
			DE(data->minus);
			DE(data->zero);
			DE(data->dot);
			DE(data->prec);
			DE(data->fill);
			DE(data->arg);
			DE(data->skip);
			DE(data->ret);
			DE(data->x_up);
}
#endif

/*        Debug         */

/*
**   .
*/

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_data	d;

	va_start(args, str);
	d.ret = 0;
	d.skip = 0;
	while (str && str[d.skip])
	{
		if (str[d.skip] == '%')
		{
			if (!(parser(str, &d, &args)))
			{
				va_end(args);
				return (ERR);
			}
		}
		else
			ft_putchar(str[d.skip++], &d);
	}
	va_end(args);
	return (d.ret);
}
