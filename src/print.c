/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:22:24 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/02 13:23:25 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

void	putstr_rev(const char *s, t_data *data)
{
	size_t	len;

	len = len_str(s);
	data->ret += len;
	while (s && len > 0 && s[--len])
		putchar(s[len]);
}

/*
** //XXX Malloc !
*/

int	print_int(int nbr, t_data *data)
{
	int		i;
	char	*str;
	int		neg;
	long	nbr_c;

	neg = 0;
	i = 0;
	if (nbr < 0)
	{
		nbr_c = nbr * -1;
		neg++;
	}
	else
		nbr_c = nbr;
	str = malloc(len_int(nbr_c) + 1 + neg);
	if (!str)
		return (-1);
	while (nbr_c > 0)
	{
		str[i] = (nbr_c % 10) + '0';
		nbr_c /= 10;
		i++;
	}
	if (neg)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	putstr_rev(str, &(*data));
	free (str);
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
