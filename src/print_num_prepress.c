/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_prepress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:43:26 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/22 13:41:58 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_arg_d(char *str, t_data *data)
{
	size_t	len;
	int		width;
	int		fill;

	len = len_str(str);
	fill_num(&len, &width, &fill, &(*data));
	
	if (!data->minus && data->fill)
	min_fill(len, width, &(*data));
	if (len && fill && str[len - 1] == '-')
	{
		str[len - 1] = '\0';
		ft_putchar('-', &(*data));
		if (data->minus)
			fill++;
	}
	if (data->fill || data->dot || data->zero)
		zero_fill(fill, &(*data));
	putstr_rev(str, &(*data));
	if (data->minus && data->fill)
		min_fill(len, width, &(*data));
}