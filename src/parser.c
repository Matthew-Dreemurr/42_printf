/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:13 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/26 16:38:22 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
**   index | flag | func
**   ------|------|------
**   [0]   | `-`  | dummy
**   [1]   | `0`  | dummy
**   [2]   | `.`  | dummy
**   [3]   | `*`  | dummy
**   [4]   | `c`  | dummy
**   [5]   | `s`  | arg_s
**   [6]   | `p`  | dummy
**   [7]   | `d`  | dummy
**   [8]   | `i`  | dummy
**   [9]   | `u`  | dummy
**   [10]  | `x`  | dummy
**   [11]  | `X`  | dummy
**   [12]  | `%`  | dummy
**
*/

int	index_flag(const char c, t_data *data, va_list *args)
{
	static t_func_arr	f[FUNC] = {
		dummy,//  [0]  | `-`
		dummy,//  [1]  | `0`
		dummy,//  [2]  | `.`
		dummy,//  [3]  | `*`
		arg_c,//  [4]  | `c`
		arg_s,//  [5]  | `s`
		dummy,//  [6]  | `p`
		dummy,//  [7]  | `d`
		dummy,//  [8]  | `i`
		dummy,//  [9]  | `u`
		dummy,//  [10] | `x`
		dummy,//  [11] | `X`
		dummy //  [12] | `%`
	};
	char *flag;
	int index;


	index = 0;
	flag = "-0.*cspdiuxX%";
	while (flag && flag[index] && flag[index] != c)
	{
		index++;
# ifdef DEBUG_TRUE
		// D_INT(index);
		// D_CHAR(flag[index]);
		BR;
# endif
	}
	if (flag[index] == c)
	{
		if (!(f[index](&(*data), &(*args))))
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

	if (*str == '%')
	{
		(void)args;
		ft_putchar(*str, &(*data));
		ret = 1;
	}
	else
		ret = index_flag(*str, &(*data), &(*args));
	return (ret);
}
