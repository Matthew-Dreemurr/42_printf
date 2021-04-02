/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:13 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/02 16:44:39 by mhadad           ###   ########.fr       */
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

int	index_flag(const char *str, t_data *d, va_list *args)
{
	static t_func_arr	f[FUNC] = {
		arg_c,         //  [0]  | `c`
		arg_s,         //  [1]  | `s`
		arg_p,         //  [2]  | `p`
		arg_d,         //  [3]  | `d`
		dummy,         //  [4]  | `i`
		dummy,         //  [5]  | `u`
		dummy,         //  [6]  | `x`
		dummy,         //  [7]  | `X`
		dummy          //  [8]  | `%`
	};
	char *flag;
	int index;


	index = 0;
	flag = "cspdiuxX%";
	while (flag && flag[index] && flag[index] != *str)
	{
		index++;
# ifdef DEBUG_TRUE
		D_STR((char *)str);
		D_INT(index);
		D_CHAR(flag[index]);
		BR;
# endif
	}
	if (flag[index] == *str)
	{
		if ((f[index](&(*d), &(*args))) == ERR)
			return (ERR);
		return (TRUE);
	}
	return (TRUE);
}

/*
**
*/

int	check_flag(const char *str, t_data *data, va_list *args)
{
	int ret;

	ret = 0;
	if (*str == '%')
	{
		// (void)args;
		ft_putchar(*str, &(*data));
		ret = 1;
	}
	else
	{
		if (str[data->skip] == '-')
		{
			data->minus++;
			data->skip++;
		}
		if (str[data->skip] == '0')
		{
			data->zero++;
			data->skip++;
		}
		if (str[data->skip] == '.')
		{
			data->prec++;
			data->skip++;
		}
		if (str[data->skip] == '*')
		{
			data->arg++;
			data->skip++;
		}
		if (str[data->skip] != '0')
		{
			if (str[data->skip] >= '1' && str[data->skip] <= '9')
				ret = min_width(&str[data->skip], &(*data));
		}
	}
#ifdef DEBUG_TRUE
		D_INT(data->minus);
		D_INT(data->zero);
		D_INT(data->arg);
		D_INT(data->min_width);
		D_INT(data->skip);
		D_INT(ret);
		BR;
#endif
	ret = index_flag(&str[data->skip], &(*data), &(*args));
	return (ret);
}
