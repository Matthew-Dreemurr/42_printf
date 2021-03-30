/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:16:18 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/30 21:51:10 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

size_t	len_str(const char *str)
{
	int	i;

	i = -1;
	if(!str && !*str)
		return (0);
	while (str[++i])
		;
	return (i);
}

/*
**
*/

int	len_int(int nbr)
{
	int len;

	if(nbr < 0)
		return (ERR);
	if (nbr == 0)
		return (0);
	len = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		len ++;
	}
	return (len);
}

/*
**
*/

void	ft_putstr(const char *s, t_data *data)
{
#ifdef DEBUG_TRUE
	write(1, "\n\n|", 4);
#endif
	data->ret += len_str(s);
	while (s && *s)
		write(1, s++, 1);
#ifdef DEBUG_TRUE
	write(1, "|\n\n", 4);
#endif
}

/*
**   Will print the carater `c` and increment `data->skip/ret`
*/

void	ft_putchar(char c, t_data *data)
{
#ifdef DEBUG_TRUE
	write(1, "\n|", 3);
#endif
	write(1, &c, 1);
	data->ret++;
#ifdef DEBUG_TRUE
	puts("|\n");
#endif
}

/*
**
*/

void	print_int(int nbr, t_data *data)
{

}

/*
**
*/

int		min_width(const char *str, t_data *data)
{
	long	len;
	int		i;

	if (!str)
		return (ERR);
	i = 0;
	len = 0;
	while (str[i] && (str[i] >= '1' && str[i] <= '9'))
	{
		len *= 10;
		len += (str[i] - '0');
		i++;
	}
	if (len > MAX_INT)
		return (ERR);
	data->min_width = len;
	data->skip += len_int(len);
#ifdef DEBUG_TRUE
	D_INT(data->min_width);
	D_INT(data->skip);
	BR;
#endif
	return (TRUE);
}

/*
**
*/

void	width_print(int len, size_t s_len, t_data *data)
{
	int	wdt_len;

	wdt_len = len - s_len;
#ifdef DEBUG_TRUE
	D_INT(len);
	D_LINT(s_len);
	D_INT(wdt_len);
	BR;
#endif
	if (wdt_len > 0)
	{
#ifdef DEBUG_TRUE
	write(1, "\n\n|", 4);
#endif
		data->ret += wdt_len;
		while (0 <= --wdt_len)
			write(1, " ", 1);
#ifdef DEBUG_TRUE
	write(1, "|\n\n", 4);
#endif
	}
}