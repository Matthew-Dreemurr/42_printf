/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:16:18 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/26 19:50:43 by mhadad           ###   ########.fr       */
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

void	ft_putstr(const char *s, t_data *data)
{
	data->ret += len_str(s);
	while (s && *s)
		write(1, s++, 1);
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

int	ascii_range(char *str, char start, char end)
{
	int	i;
	int	j;

	if (start < end || !str)
		return (FALSE);
	while (start <= end)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == start)
				return (FALSE);
			i++;
		}
		start++;
	}
	
}