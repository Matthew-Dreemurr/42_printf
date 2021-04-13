/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:55:34 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/13 17:07:25 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_arg_s(char *str, t_data *data)
{
	size_t	len;

	len = len_str(str);
	if (!data->minus && data->chartoi)
		width_print(data->chartoi, len_str(str), &(*data));
	if (data->max_print < len)
		str[data->max_print] = '\0';
	ft_putstr(str, &(*data));
	return (TRUE);
}

