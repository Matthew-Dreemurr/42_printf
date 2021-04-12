/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:20:01 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/12 12:50:40 by mhadad           ###   ########.fr       */
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

int		flag_min(const char *str, t_data *data, va_list *args)
{
	(void)str;
	data->skip++;
	(void)args;
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
	data->skip++;
	(void)args;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}

/*
**
*/

int		flag_dot(const char *str, t_data *data, va_list *args)
{
	(void)str;
	data->skip++;
	(void)args;
#ifdef DEBUG_TRUE
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
	data->skip++;
	(void)args;
#ifdef DEBUG_TRUE
	BR;
#endif
	return (TRUE);
}