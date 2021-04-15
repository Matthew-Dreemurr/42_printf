/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:55:34 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/15 15:18:40 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_arg_s(const char *str, t_data *data)
{
	size_t	len;

	len = len_str(str);
#ifdef DEBUG_TRUE
D_STR_DETAILS(str);
DE(len);
#endif
	if (!data->minus && data->width)
		width_print(data->width, len, &(*data));
	ft_putstr(str, &(*data));
	if (data->minus && data->width)
		width_print(data->width, len, &(*data));
	data->skip++;
	return (TRUE);
}

