/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:02:57 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/19 18:14:21 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

void	min_width(size_t str_len, t_data *data)
{
	int		wdt_len;

#ifdef DEBUG_TRUE
	BM("min_width");
	DE(str_len);
	data_debug(&(*data));
	BR;
#endif

	wdt_len = data->width - str_len;
	if (wdt_len < 0)
		wdt_len = 0;
#ifdef DEBUG_TRUE
	DE(str_len);
	DE(wdt_len);
	data_debug(&(*data));
	BR;
#endif

		data->ret += wdt_len;
		while (0 <= --wdt_len)
			write(1, " ", 1);
			
#ifdef DEBUG_TRUE
	data_debug(&(*data));
	BR;
#endif
}

/*
**
**
*/

void	zero_fill(size_t str_len, t_data *data)
{
	int		acc_len;

#ifdef DEBUG_TRUE
	BM("zero_fill");
	DE(str_len);
	data_debug(&(*data));
	BR;
#endif

	if (data->zero && !data->acc)
		data->acc = data->width;
	acc_len = data->acc - str_len;
	if (acc_len < 0)
		acc_len = 0;

#ifdef DEBUG_TRUE
	DE(str_len);
	DE(acc_len);
	data_debug(&(*data));
	BR;
#endif

	data->ret += acc_len;
	while (0 <= --acc_len)
		write(1, "0", 1);
#ifdef DEBUG_TRUE
	data_debug(&(*data));
	BR;
#endif
}