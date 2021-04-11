/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:40:39 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/11 13:51:20 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*        Debug         */

#ifdef DEBUG_TRUE
void	data_debug(t_data *data)
{
			D_INT(data->minus);
			D_INT(data->zero);
			D_INT(data->dot);
			D_INT(data->width);
			D_INT(data->arg);
			D_INT(data->skip);
			D_INT(data->ret);
}
#endif

/*        Debug         */

/*
**
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
		if (str[d.skip] = '%')
			ft_putchar();
	}
	
	va_end(args);
	return (d.ret);
}
