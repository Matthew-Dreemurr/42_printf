/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:10:37 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/30 17:33:35 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	arg_c(t_data *data, va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	if (data->min_width && !data->minus)
		width_print(data->min_width, 1, &(*data));
	ft_putchar(c, &(*data));
	data->skip++;
	if (data->min_width && data->minus)
		width_print(data->min_width, 1, &(*data));
#ifdef DEBUG_TRUE
BR;
#endif
	return (TRUE);
}

/*
**   if `str` is null len = 6 (len_str("(null)"))
*/

int	arg_s(t_data *data, va_list *args)
{
	const char	*str;
	size_t		len;
	str = (const char *)va_arg(*args, const char * );
#ifdef DEBUG_TRUE
	D_STR_DETAILS((char *)str);
	BR;
#endif
	if (str && *str)
		len = len_str(str);
	else
		len = 6;
	if (data->min_width && !data->minus)
		width_print(data->min_width, len, &(*data));
	if (!str || !*str)
		ft_putstr("(null)", &(*data));
	else
		ft_putstr(str, &(*data));
	if (data->min_width && data->minus)
	{
		width_print(data->min_width, len, &(*data));
	}
	data->skip++;
	return (TRUE);
}
