/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:13 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/07 13:15:25 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
**   index | flag | func
**   ------|------|------
**   [0]   | `c`  | arg_c
**   [1]   | `s`  | arg_s
**   [2]   | `p`  | dummy
**   [3]   | `d`  | dummy
**   [4]   | `i`  | dummy
**   [5]   | `u`  | dummy
**   [6]   | `x`  | dummy
**   [7]   | `X`  | dummy
**   [8]   | `%`  | dummy
**
*/

int	pars_arg(const char *str, t_data *d, va_list *args)
{
	static t_func_arr	f[ARG_FUNC] = {
		arg_c,
		arg_s,
		arg_p,
		arg_d,
		arg_d,
		arg_u,
		arg_x,
		arg_x_up,
		dummy
	};
	char				*list;
	int					index;

	index = 0;
	list = "cspdiuxX%";
	while (list && list[index] && list[index] != *str)
	{
		index++;
	}
	if (list[index] == *str)
	{
		if ((f[index](&(*d), &(*args))) == ERR)  //XXX WIP Need to check if no flag find
			return (ERR);
		return (TRUE);
	}
	return (TRUE);
}

/*
**
**   Flag `-0.*`
**   index | flag | func
**   ------|------|------
**   [0]   | `-`  | flag_min
**   [1]   | `0`  | arg_s
**   [2]   | `.`  | dummy
**   [3]   | `*`  | dummy
*/

int	flag_check(const char *str, t_data *data, va_list *args)
{
	int					index;
	char				list;
	static t_func_arr	f[FLAG_FUNC] = {
		flag_min,
		dummy,
		dummy,
		dummy
	};

	index = 0;
	list = "-0.*";
	while (str[data->skip] != list[index])
		index++;
	if ((f[index](str, &(*data), &(*args))) == ERR)  //XXX WIP Need to check if no flag find
		return (ERR);
	return (FALSE);
}

/*
**   //TODO   Pars only when a flag is occured, check if isnum && while !flag
**   Flag `-0.*`
*/

int	pars_flag(const char *str, t_data *data, va_list *args)
{
	int	ret;

	ret = 0;
	if (*str == '%')
	{
		ft_putchar(*str, &(*data));
		data->skip += 1;
		return (TRUE);
	}
	else
	{
		wihle (str[data->skip])
		{
			ret = flag_check(str, &(*data), &(*args);
			if (ret == TRUE))
				break;
			if (ret == ERR))
				return (ERR);
		}
	}
	return (pars_arg(&str[data->skip], &(*data), &(*args)));
}
