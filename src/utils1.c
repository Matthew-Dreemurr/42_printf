/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:13 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/25 14:59:25 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**   Will print the carater `c` and increment `data->skip/ret`
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
**   Will print the carater `c` and increment `data->skip/ret`
*/

void	ft_putchar(char c, t_data *data)
{
#ifdef DEBUG_TRUE
	write(1, "\n[\0", 4);
#endif
	write(1, &c, 1);
	data->skip++;
	data->ret++;
#ifdef DEBUG_TRUE
	puts("]\n");
#endif
}

/*
**  `%-` | `min`  | Left align the result within the given field width
**  `%0` | `zero` | Shorter numbers are padded out with leading zeros
**  `%.` | `prec` | How many placesshould be shown after the decimal point
**  `%*` | `arg`  | an int width argument must precede the value that's being
**                   formatted in the argument list, exemple 
**                   `printf("%0*d", 5, 3); ` 00003 is output`
*/

void	data_init(t_data *data)
{
	data->min = 0;
	data->zero = 0;
	data->prec = 0;
	data->arg = 0;
	data->skip = 0;
}

/*
**
*/

int	index_flag(const char c, t_data *data, va_list *args)
{
	static t_func_arr	(*f)[FUNC] = {
		arg_s,
		arg_c
	};
	char *index;
	int i;


	i = -1;
	index = "-0.*cspdiuxX%";
	while (index && index[++i] && index[i] != c )
		;
	
	
}

/*
**
*/

int	check_flag(const char *str, t_data *data, va_list *args)
{
	if (*str == '%')
	{
		(void)args;
		ft_putchar(*str, &(*data));
		data->skip++;                                     //To skip the `%` flag
		return (TRUE);
	}
	else if ((index_flag(str, &data, &args)) == ERR)
		return (ERR);
#ifdef DEBUG_TRUE
	D_INT(data->min);
	D_INT(data->zero);
	D_INT(data->prec);
	D_INT(data->arg);
	D_INT(data->skip);
	D_INT(data->ret);
	D_STR(str);
	BR;
#endif
	return (TRUE);
}
