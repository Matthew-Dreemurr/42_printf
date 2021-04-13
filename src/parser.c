/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:13 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/13 17:22:02 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**  `%-` | `min`  | Left align the result within the given field chartoi
**  `%0` | `zero` | Shorter numbers are padded out with leading zeros
**  `%.` | `dot` | How many placesshould be shown after the decimal point
**  `%*` | `arg`  | an int chartoi argument must precede the value that's being
**                   formatted in the argument list, exemple 
**                   `printf("%0*d", 5, 3); ` 00003 is output`
*/

void	data_init(t_data *data)
{
	data->minus = 0;
	data->zero = 0;
	data->dot = 0;
	data->chartoi = 0;
	data->max_print = 0;
	data->arg = 0;
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
**   Return | Value
**   -------|------
**
*/

int	arg_check(const char *str, t_data *d, va_list *args)
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

#ifdef DEBUG_TRUE
BM("arg_check");
#endif

	index = 0;
	list = "cspdiuxX%";
	while (list && list[index] && list[index] != str[d->skip])
		index++;

#ifdef DEBUG_TRUE
data_debug(&(*d));
D_STR(&(list[index]))
D_INT(index)
BR;
#endif

	if (list[index] == str[d->skip])
	{
		if ((f[index](NULL, &(*d), &(*args))) == ERR)  //XXX WIP Need to check if no flag find
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
**
**   Return | Value
**   -------|------
**   TRUE   |  1
**   FALSE  |  0
*/

int	flag_check(const char *str, t_data *data, va_list *args)
{
	int					index;
	int					ret;
	char				*list;
	static t_func_arr	f[FLAG_FUNC] = {
		flag_min,
		flag_zero,
		flag_dot,
		flag_arg,
		dummy_flag
	};

#ifdef DEBUG_TRUE
BM("Flag_check");
#endif

	index = 0;
	ret = 0;
	list = "-0.*";
	while(!str && str[data->skip])
		if (str[data->skip] >= '1' && str[data->skip] <= '9')
			if (!(chartoi(str, &(*data))))
				return (FALSE);
		else
		{
			while (list[index] && str[data->skip] != list[index])
			{
#ifdef DEBUG_TRUE
D_INT(index);
#endif
				index++;
			}
			ret = f[index](str, &(*data), &(*args));
			if (ret == ERR)
				return (FALSE);
			if (!ret)
				break;
		}
#ifdef DEBUG_TRUE
data_debug(&(*data));
BR;
#endif
	return (arg_check(str, &(*data), &(*args)));
}

/*
**   Flag `-0.*`
*/

int	parser(const char *str, t_data *data, va_list *args)
{
	if (!str[++data->skip])
		return (FALSE);
#ifdef DEBUG_TRUE
BM("str++ ok");
D_STR_DETAILS(&str[data->skip]);
D_INT(data->skip);
#endif
	data_init(&(*data));
	if (str[data->skip] == '%')
		ft_putchar(str[data->skip++], &(*data));
	else
		if (!flag_check(str, &(*data), &(*args)))
			return(FALSE);
	return (TRUE);
}
