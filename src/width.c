/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:02:57 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/28 17:10:16 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**   .
*/

void	min_fill(size_t str_len, int wdt_len, t_data *data)
{
	wdt_len -= str_len;
	if (wdt_len < 0)
		wdt_len = 0;
	data->ret += wdt_len;
	while (0 <= --wdt_len)
		write(1, " ", 1);
}

/*
**   .
*/

void	zero_fill(int prec_len, t_data *data)
{
	data->ret += prec_len;
	while (0 <= --prec_len)
		write(1, "0", 1);
}

/*
**   .
*/

void	fill_num(size_t *len, int *width, int *fill, t_data *data)
{
	*fill = 0;
	*width = data->fill;
	if (data->zero)
		if (*len < data->fill)
			*fill = data->fill - *len;
	if (data->dot)
	{
		if ((int)*len < data->prec)
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