/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:55:34 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/16 17:01:47 by mhadad           ###   ########.fr       */
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
#ifdef DEBUG_TRUE
BM("print_arg_s");
D_STR_DETAILS(str);
DE(len);
#endif
	if (!data->minus && data->width)
		width_blank(len, &(*data));
	ft_putstr(str, &(*data));
	if (data->minus && data->width)
		width_blank(len, &(*data));
}

/*
**
*/

void	print_arg_c(const char c, t_data *data)
{
	data->dot = 0;
	data->max_print = 0;
	if (!data->minus && data->width)
		width_blank(1, &(*data));
	ft_putchar(c, &(*data));
	if (data->minus && data->width)
		width_blank(1, &(*data));
}

/*
**
*/

void	print_arg_x(const char *str, t_data *data)
{
	size_t	len;

	len = len_str(str);
	if (!data->minus && (data->width || data->dot))
		width_blank(len, &(*data));
	putstr_rev(str, &(*data));
	if (data->minus && (data->width || data->dot))
		width_blank(len, &(*data));
}