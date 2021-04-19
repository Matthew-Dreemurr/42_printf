/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:55:34 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/19 18:40:15 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

void	print_arg_s(const char *str, t_data *data)
{
	size_t	len;

	len = len_str(str);
	if (data->dot && len > data->acc)
		len = data->acc;

#ifdef DEBUG_TRUE
BM("print_arg_s");
D_STR_DETAILS(str);
DE(len);
#endif
	if (!data->minus && data->width)
		min_width(len, data->width, &(*data));
	ft_putstr(str, &(*data));
	if (data->minus && data->width)
		min_width(len, data->width, &(*data));
}

/*
**
*/

void	print_arg_c(const char c, t_data *data)
{
	data->dot = 0;
	data->acc = 0;
	if (!data->minus && data->width)
		min_width(1, data->width, &(*data));
	ft_putchar(c, &(*data));
	if (data->minus && data->width)
		min_width(1, data->width, &(*data));
}

/*
**
*/

void	print_arg_x(const char *str, t_data *data)
{
	size_t	len;
	size_t	str_len_w;

	len = len_str(str);
	str_len_w = len;
	if (data->dot && len < data->acc)
		str_len_w = data->width - (data->acc - len);

#ifdef DEBUG_TRUE
	BM("print_arg_x");
	DE(len);
	DE(str_len_w);
	BR;
#endif

	if (!data->minus && data->width)
		min_width(str_len_w, &(*data));
	if (data->width || data->dot || data->zero)
		zero_fill(len, &(*data));
	putstr_rev(str, &(*data));
	if (data->minus && data->width)
		min_width(str_len_w, &(*data));
}