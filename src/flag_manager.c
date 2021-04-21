/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:20:01 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/21 17:46:44 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
** //XXX check V2
*/

int	flag_min(const char *str, t_data *data, va_list *args)
{
	data->skip++;
	data->minus++;
	if (str[data->skip] >= '0' && str[data->skip] <= '9')
		data->fill = chartoi(&str[data->skip], &(*data));
	else if (str[data->skip] == '*')
	{
		data->fill = (int)va_arg(*args, int);
		data->skip++;
	}
	else
		data->fill = 0;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}

/*
**   .
*/

int		flag_zero(const char *str, t_data *data, va_list *args)
{
	data->skip++;
	data->zero++;
	if (str[data->skip] >= '0' && str[data->skip] <= '9')
		data->fill = chartoi(&str[data->skip], &(*data));
	else if (str[data->skip] == '*')
	{
		data->fill = (int)va_arg(*args, int);
		data->skip++;
	}
	else
		data->fill = 0;
#ifdef DEBUG_TRUE
	BM("flag_zero");
	BR;
#endif
	return (TRUE);
}

/*
** Skip the '.', check if isnum if !, check if '*' and take the next args if !, dot = 0
*/

int		flag_dot(const char *str, t_data *data, va_list *args)
{
	data->skip++;
	data->dot++;
	if (str[data->skip] >= '0' && str[data->skip] <= '9')
		data->prec = chartoi(&str[data->skip], &(*data));
	else if (str[data->skip] == '*')
	{
		data->prec = (int)va_arg(*args, int);
		data->skip++;
	}
	else
		data->prec = 0;
#ifdef DEBUG_TRUE
	D_STR_DETAILS(&str[data->skip]);
	BR;
#endif
	return (TRUE);
}

/*
**   .
*/

int		flag_arg(const char *str, t_data *data, va_list *args)
{
	(void)str;
	data->fill = (int)va_arg(*args, int);
	data->skip++;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}