/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:13 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/29 22:53:25 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/* //TODO
** //TODO Need to remove the flags form the index and check before 
*/ //TODO  call index_flag.

int	left_justify(t_data *data, va_list *args)
{
	(void)args;
	data->minus++;
	data->skip++;
	return (TRUE);
}

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

int	index_flag(const char *str, t_data *d, va_list *args)
{
	static t_func_arr	f[FUNC] = {
		left_justify,  //  [0]  | `-`
		dummy,         //  [1]  | `0`
		dummy,         //  [2]  | `.`
		dummy,         //  [3]  | `*`
		arg_c,         //  [4]  | `c`
		arg_s,         //  [5]  | `s`
		dummy,         //  [6]  | `p`
		dummy,         //  [7]  | `d`
		dummy,         //  [8]  | `i`
		dummy,         //  [9]  | `u`
		dummy,         //  [10] | `x`
		dummy,         //  [11] | `X`
		dummy          //  [12] | `%`
	};
	char *flag;
	int index;


	index = 0;
	flag = "-0.*cspdiuxX%";
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
		if (!(f[index](&(*d), &(*args))))
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
		// (void)args;
		ft_putchar(*str, &(*data));
		ret = 1;
	}
	else if (*str != '0')
	{
		if (*str >= '1' && *str <= '9')
			ret = min_width(str, &(*data));
#ifdef DEBUG_TRUE
		D_INT(data->min_width);
		D_INT(data->skip);
#endif
	}
	ret = index_flag(&str[data->skip], &(*data), &(*args));
	return (ret);
}
