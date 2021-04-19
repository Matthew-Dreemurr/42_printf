/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:12:36 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/19 18:12:40 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
