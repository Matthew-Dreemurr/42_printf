/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:55:34 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/21 17:46:20 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**   .
*/

void	print_arg_s(const char *str, t_data *data)
{
	size_t	len;

	len = len_str(str);
	if (data->dot && len > data->prec)
		len = data->prec;
	if (!data->minus && data->fill)
		min_fill(len, data->fill, &(*data));
	ft_putstr(str, &(*data));
	if (data->minus && data->fill)
		min_fill(len, data->fill, &(*data));
}

/*
**   .
*/

void	print_arg_c(const char c, t_data *data)
{
	data->dot = FALSE;
	data->prec = FALSE;
	if (!data->minus && data->fill)
		min_fill(1, data->fill, &(*data));
	ft_putchar(c, &(*data));
	if (data->minus && data->fill)
		min_fill(1, data->fill, &(*data));
}

/*
**   .
*/

void	fill_arg_x(size_t *len, int *width, int *fill, t_data *data)
{
	*fill = 0;
	*width = data->fill;
	if (data->zero)
		if (*len < data->fill)
			*fill = data->fill - *len;
	if (data->dot)
	{
		if (*len < data->prec)
			*fill = data->prec - *len;
		else
			*fill = 0;
	}
	if (*fill < 0)
		*fill = 0;
	*width -= *fill;
	if (*width < 0)
		*width = 0;
}

/*
**   .
*/

void	print_arg_x(const char *str, t_data *data)
{
	size_t	len;
	int		width;
	int		fill;

	len = len_str(str);
	if (data->dot && !data->prec && *str == '0')
	{
		width = data->fill;
		len = 0;
	}
	fill_arg_x(&len, &width, &fill, &(*data));
	if (!data->minus && data->fill)
		min_fill(len, width, &(*data));
	if (data->fill || data->dot || data->zero)
		zero_fill(fill, &(*data));
	if (data->dot && !data->prec && *str == '0')
		;
	else
		putstr_rev(str, &(*data));
	if (data->minus && data->fill)
		min_fill(len, width, &(*data));
}
