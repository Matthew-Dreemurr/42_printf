/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:16:18 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/29 16:56:59 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

int	len_str(const char *str)
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
	D_STR_DETAILS((char *)s);
	BR;
#endif
	data->ret += len_str(s);
	while (s && *s)
		write(1, s++, 1);
#ifdef DEBUG_TRUE
	D_STR_DETAILS((char *)s);
	BR;
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

// int	ascii_range(char *str, char start, char end)
// {
// 	int	i;
// 	int	j;
// 	if (start < end || !str)
// 		return (FALSE);
// 	while (start <= end)
// 	{
// 		i = 0;
// 		while (str[i])
// 		{
// 			if (str[i] == start)
// 				return (FALSE);
// 			i++;
// 		}
// 		start++;
// 	}
// 	return (FALSE);
// }

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
		return (-1);
	data->min_width = len;
	data->skip = len_int(len);
	return (TRUE);
}