/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:22:24 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/07 11:59:54 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

void	ft_putstr(const char *s, t_data *data)
{
	ssize_t	len;

	len = 0;
	if (!data->prec)
		len = len_str(s);
	else
		len = data->min_width;
	data->ret += len;
	while (s && *s && len--)
	{
		write(1, s++, 1);
	}
}

/*
**   Will print the carater `c` and increment `data->skip/ret`
*/

void	ft_putchar(char c, t_data *data)
{
	write(1, &c, 1);
	data->ret++;
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
		write(1, &(s[len]), 1);
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
		return (FALSE);
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
** //XXX Malloc !
*/

int	print_uint(unsigned int nbr, t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(len_uint(nbr) + 1);
	if (!str)
		return (FALSE);
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
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
	int		wdt_len;
	char	c;
	wdt_len = len - s_len;
	c = ' ';
	if (data->zero)
		c = '0';
	if (wdt_len > 0)
	{
		data->ret += wdt_len;
		while (0 <= --wdt_len)
			write(1, &c, 1);
	}
}
