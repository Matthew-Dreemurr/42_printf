/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:43:13 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/23 16:05:38 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**   Will print the carater `c`
*/

void	ft_putchar(char c, t_data *data)
{
#ifdef DEBUG_TRUE
	write(1, "[\0", 2);
#endif
	data->skip += write(1, &c, 1);
	data->ret += data->skip;
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

int	check_flag(const char *str, t_data *data, va_list *args)
{
	(void)args;
	if (*str == '%')
	{
		ft_putchar(*str, &(*data));
		data->skip++;                                     //To skip the `%` flag
		return (TRUE);
	}
	if (*str == '-')
		data->min++;
	if (*str == '0')
		data->zero++;
	if (*str == '*')
		data->arg++;
	if (*str == '.')
		data->prec++;
	return (TRUE);
}
