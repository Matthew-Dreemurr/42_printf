/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:10:37 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/25 18:42:47 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	arg_c(t_data *data, va_list *args)
{
	(void)data;
	(void)args;
	puts("arg_c");
	return (TRUE);
}

int	arg_s(t_data *data, va_list *args)
{
	const char *str;

	(void)data;
	(void)args;
	str = (const char *)va_arg(*args, const char * );
	ft_putstr(str, &(*data));
	data->skip++;
	return (TRUE);
}
