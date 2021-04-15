/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:20:01 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/15 16:55:10 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

int	dummy_flag(const char *str, t_data *data, va_list *args)
{
	(void)str;
	(void)data;
	(void)args;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (FALSE);
}

/*
**
*/

int	flag_min(const char *str, t_data *data, va_list *args)
{
	(void)str;
	(void)args;
	data->skip++;
	data->minus++;
	if (str[data->skip] >= '0' && str[data->skip] <= '9')
		data->width = chartoi(&str[data->skip], &(*data));
	else if (str[data->skip] == '*')
	{
		data->width = (int)va_arg(*args, int);
		data->skip++;
	}
	else
		data->width = 0;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}

/*
**
*/

int		flag_zero(const char *str, t_data *data, va_list *args)
{
	(void)str;
	(void)args;
	data->skip++;
#ifdef DEBUG_TRUE
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
		data->max_print = chartoi(&str[data->skip], &(*data));
	else if (str[data->skip] == '*')
	{
		data->max_print = (int)va_arg(*args, int);
		data->skip++;
	}
	else
		data->max_print = 0;
#ifdef DEBUG_TRUE
	D_STR_DETAILS(&str[data->skip]);
	BR;
#endif
	return (TRUE);
}

/*
**
*/

int		flag_arg(const char *str, t_data *data, va_list *args)
{
	(void)str;
	data->width = (int)va_arg(*args, int);
	data->skip++;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}