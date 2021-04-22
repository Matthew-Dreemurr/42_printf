/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_prepress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:55:34 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/22 14:13:17 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**   .
*/

void	print_arg_x(const char *str, t_data *data)
{
	size_t	len;
	int		width;
	int		fill;

	len = len_str(str);
	if (data->dot && !data->prec && str[0] == '0' && str[1] == '\0')
	{
		width = data->fill;
		len = 0;
	}
	fill_num(&len, &width, &fill, &(*data));
	if (!data->minus && data->fill)
		min_fill(len, width, &(*data));
	if (data->fill || data->dot || data->zero)
		zero_fill(fill, &(*data));
	if (data->dot && !data->prec && str[0] == '0' && str[1] == '\0')
		;
	else
		putstr_rev(str, &(*data));
	if (data->minus && data->fill)
		min_fill(len, width, &(*data));
}

/*
**   .
*/

void	print_arg_p(const char *str, t_data *data)
{
	size_t	len;

	len = len_str(str) + 2;
	if (!data->minus && data->fill)
		min_fill(len, data->fill, &(*data));
	ft_putstr("0x", &(*data));
	putstr_rev(str, &(*data));
	if (data->minus && data->fill)
		min_fill(len, data->fill, &(*data));
}