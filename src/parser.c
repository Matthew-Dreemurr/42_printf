/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:13 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/10 17:10:19 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**  `%-` | `min`  | Left align the result within the given field width
**  `%0` | `zero` | Shorter numbers are padded out with leading zeros
**  `%.` | `dot` | How many placesshould be shown after the decimal point
**  `%*` | `arg`  | an int width argument must precede the value that's being
**                   formatted in the argument list, exemple 
**                   `printf("%0*d", 5, 3); ` 00003 is output`
*/

void	data_init(t_data *data)
{
	data->minus = 0;
	data->zero = 0;
	data->dot = 0;
	data->arg = 0;
	data->skip = 0;
	data->width = 0;
	data->x_up = 0;
}


/*
**
**   index | flag | func
**   ------|------|------
**   [0]   | `c`  | arg_c
**   [1]   | `s`  | arg_s
**   [2]   | `p`  | dummy_arg
**   [3]   | `d`  | dummy_arg
**   [4]   | `i`  | dummy_arg
**   [5]   | `u`  | dummy_arg
**   [6]   | `x`  | dummy_arg
**   [7]   | `X`  | dummy_arg
**   [8]   | `%`  | dummy_arg
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
		dummy_arg
	};
	char				*list;
	int					index;

	index = 0;
	list = "cspdiuxX%";
	while (list && list[index] && list[index] != *str)
	{
#ifdef DEBUG_TRUE
		D_STR_DETAILS(str);
		D_INT(d->minus);
		D_INT(d->zero);
		D_INT(d->dot);
		D_INT(d->width);
		D_INT(d->arg);
		D_INT(d->skip);
		D_INT(d->ret);
		BR;
#endif
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
**   [1]   | `0`  | dummy_arg
**   [2]   | `.`  | dummy_arg
**   [3]   | `*`  | dummy_arg
*/

int	flag_check(const char *str, t_data *data, va_list *args)
{
	int					index;
	char				*list;
	static t_func_arr	f[FLAG_FUNC] = {
		flag_min,
		flag_zero,
		flag_dot,
		flag_arg,
		dummy_flag
	};

	index = 0;
	list = "-0.*";
	
	if (str[data->skip] >= '1' && str[data->skip] <= '9')
		width(str, &(*data));
	else
	{
		while (list[index] && str[data->skip] != list[index])
		{
#ifdef DEBUG_TRUE
			D_STR_DETAILS(&str[data->skip]);
			D_INT(data->minus);
			D_INT(data->zero);
			D_INT(data->dot);
			D_INT(data->width);
			D_INT(data->arg);
			D_INT(data->skip);
			D_INT(data->ret);
			D_INT(index);
			D_STR(&list[index]);
			BR;
#endif
			index++;
		}
		if ((f[index](str, &(*data), &(*args)) == ERR))  //XXX WIP Need to check if no flag find
			return (ERR);
	}
	if (index == (FLAG_FUNC - 1))
		return (TRUE);
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
		while (str[data->skip])
		{
#ifdef DEBUG_TRUE
			D_STR_DETAILS(&str[data->skip]);
			D_INT(data->minus);
			D_INT(data->zero);
			D_INT(data->dot);
			D_INT(data->width);
			D_INT(data->arg);
			D_INT(data->skip);
			D_INT(data->ret);
			BR;
#endif
			ret = flag_check(str, &(*data), &(*args));
			if (ret == TRUE)
				break;
			if (ret == ERR)
				return (ERR);
		}
	}
	return (pars_arg(&str[data->skip], &(*data), &(*args)));
}

