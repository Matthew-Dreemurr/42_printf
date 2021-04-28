/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_prepress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:43:26 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/28 13:40:45 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_arg_d(int nbr, char *str, t_data *data)
{
	size_t	len;
	int		width;
	int		fill;
	int		neg;

	neg = 0;
	len = len_str(str);
	DE(len);
	D_STR_DETAILS(str);
	if (len && str[len - 1] == '-' && ++neg)
	{
		str[len - 1] = '\0';
		if (data->dot && len != 1)
		{
			len--;
			DE(len);
		}
	}
	fill_num(&len, &width, &fill, data);
#ifdef DEBUG_TRUE
	BM("print_arg_d");
	data_debug(data);
#endif
	if (neg && data->prec)
		width--;
	if (data->dot && !data->prec && !nbr)
		width++;
	if (!data->minus && data->fill)
		min_fill(len, width, data);
	if (neg)
		ft_putchar('-', data);
	if (data->fill || data->dot || data->zero)
		zero_fill(fill, data);
	if (data->dot && !data->prec && str[0] == '0' && str[1] == '\0')
		;
	else
		putstr_rev(str, data);
	if (data->minus && data->fill)
		min_fill(len, width, data);
}
