/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:22:24 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/19 14:48:38 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

void	ft_putstr(const char *s, t_data *data)
{
	size_t	i;
	size_t	max;


#ifdef DEBUG_TRUE
BM("ft_pustr");
data_debug(&(*data));
BR;
#endif

	max = data->acc;
	i = 0;
	if (!data->dot)
		max = len_str(s);
	while (s && s[i] && max--)
		write(1, &s[i++], 1);

#ifdef DEBUG_TRUE
	data_debug(&(*data));
	DE(i);
	BR;
#endif

	data->ret += i;
}

/*
**   Will print the carater `c` and increment `data->skip/ret`
*/

void	ft_putchar(char c, t_data *data)
{
#ifdef DEBUG_TRUE
	D_INT(c);
#endif
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

void	width_str(size_t str_len, t_data *data)
{
	int		len;
	int		wdt_len;

	len = data->width;
#ifdef DEBUG_TRUE
	BM("width_print");
	DE(str_len);
	DE(len);
	DE(wdt_len);
	data_debug(&(*data));
	BR;
#endif

	if (data->dot && str_len > data->acc)
		str_len = data->acc;
	wdt_len = len - str_len;

#ifdef DEBUG_TRUE
	DE(str_len);
	DE(len);
	DE(wdt_len);
	data_debug(&(*data));
	BR;
#endif

	if (wdt_len > 0)
	{
		data->ret += wdt_len;
		while (0 <= --wdt_len)
			write(1, " ", 1);
	}
#ifdef DEBUG_TRUE
	data_debug(&(*data));
	BR;
#endif
}

// /*
// **
// */

// void	width_str(size_t str_len, t_data *data)
// {
// 	int		wdt_len;

// #ifdef DEBUG_TRUE
// 	BM("width_str");
// 	DE(str_len);
// 	data_debug(&(*data));
// 	BR;
// #endif

// 	wdt_len = data->width - (data->acc);
// 	if (wdt_len < 0)
// 		wdt_len = 0;

// #ifdef DEBUG_TRUE
// 	DE(str_len);
// 	DE(wdt_len);
// 	data_debug(&(*data));
// 	BR;
// #endif

// 		data->ret += wdt_len;
// 		while (0 <= --wdt_len)
// 			write(1, " ", 1);
// #ifdef DEBUG_TRUE
// 	data_debug(&(*data));
// 	BR;
// #endif
// }

/*
**  TODO use this function /w `width_str` for `width` + `data->acc`
**    ex: printf("%8.5x", 123) => |   0007b|
*/

void	width_nbr(size_t str_len, t_data *data)
{
	int		acc_len;

#ifdef DEBUG_TRUE
	BM("width_nbr");
	DE(str_len);
	data_debug(&(*data));
	BR;
#endif

	if (data->zero && !data->acc)
		data->acc = data->width;
	acc_len = data->acc - str_len;
	if (acc_len < 0)
		acc_len = 0;

#ifdef DEBUG_TRUE
	DE(str_len);
	DE(acc_len);
	data_debug(&(*data));
	BR;
#endif

		data->ret += acc_len;
		while (0 <= --acc_len)
			write(1, "0", 1);
#ifdef DEBUG_TRUE
	data_debug(&(*data));
	BR;
#endif
}