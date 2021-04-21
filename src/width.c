/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:02:57 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/21 17:46:44 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**   .
*/

void	min_fill(size_t str_len, int wdt_len, t_data *data)
{
#ifdef DEBUG_TRUE
	BM("min_fill");
	DE(str_len);
	data_debug(&(*data));
	BR;
#endif

	wdt_len -= str_len;
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

void	zero_fill(int prec_len, t_data *data)
{
#ifdef DEBUG_TRUE
	BM("zero_fill");
	DE(str_len);
	DE(prec_len);
	data_debug(&(*data));
	BR;
#endif

	data->ret += prec_len;
	while (0 <= --prec_len)
		write(1, "0", 1);
#ifdef DEBUG_TRUE
	data_debug(&(*data));
	BR;
#endif
}