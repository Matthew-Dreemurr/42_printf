/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_alpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:10:37 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/19 18:19:37 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
**   Return | Value
**   -------|------
**   TRUE   |  1
**   FALSE  |  0
*/

int	arg_c(const char *str, t_data *data, va_list *args)
{
	char	c;

#ifdef DEBUG_TRUE
BM("arg_c");
#endif

	(void)str;
	c = (char)va_arg(*args, int);
	print_arg_c(c, &(*data));
	data->skip++;
	return (TRUE);
}

/*
**   if `s` is null len = 6 (len_str("(null)"))
**   Return | Value
**   -------|------
**   TRUE   |  1
*/

int	arg_s(const char *str, t_data *data, va_list *args)
{
	const char	*s;

#ifdef DEBUG_TRUE
BM("arg_s");
#endif

	(void)str;
	s = (const char *)va_arg(*args, const char *);
	if (!s)
	{
		print_arg_s(STR_NULL, &(*data));
		data->skip++;
		return (TRUE);
	}
	print_arg_s(s, &(*data));
	data->skip++;
	return (TRUE);
}
