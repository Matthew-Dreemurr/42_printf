/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:16:18 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/03 16:33:00 by mhadad           ###   ########.fr       */
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
	int		len;
	long	nbr_c;

	len = 0;
	if (nbr < 0)
	{
		nbr_c = nbr * -1;
		len++;
	}
	else
		nbr_c = nbr;
	if (nbr_c == 0)
		return (0);
	while (nbr_c > 0)
	{
		nbr_c /= 10;
		len ++;
	}
	return (len);
}

/*
**
*/

int	min_width(const char *str, t_data *data)
{
	long	len;
	int		i;

	if (!str)
		return (ERR);
	i = 0;
	len = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		len *= 10;
		len += (str[i] - '0');
		i++;
	}
	if (len > MAX_INT)
		return (ERR);
	data->min_width = len;
	data->skip += len_int(len);
	return (TRUE);
}

/*
**
*/

char*	addrtohex(void *ptr)
{
	unsigned long	addr;
	char			*index;
	char			*ret;
	int				i;

	i = 0;
	index = "0123456789abcdef";
	addr = (unsigned long)ptr;
	ret = (char *)malloc(32);
	if (!ret)
		return (NULL);
	while (addr > 0)
	{
		ret[i] = index[addr % 16];
		addr /= 16;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
