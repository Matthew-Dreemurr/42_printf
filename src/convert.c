/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:10:37 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/29 18:15:14 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	arg_c(t_data *data, va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	ft_putchar(c, &(*data));
	data->skip++;
#ifdef DEBUG_TRUE
BR;
#endif
	return (TRUE);
}

int	arg_s(t_data *data, va_list *args)
{
	const char	*str;

	str = (const char *)va_arg(*args, const char * );
#ifdef DEBUG_TRUE
	D_STR_DETAILS((char *)str);
	BR;
#endif
	if (data->min_width)
	{
		// TODO check the whidth and the L/R justify
	}
	if (!str || !*str)
		ft_putstr("(null)", &(*data));
	else
		ft_putstr(str, &(*data));
	data->skip++;
	return (TRUE);
}
