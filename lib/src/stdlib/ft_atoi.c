/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:36:36 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/15 14:09:29 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *c)
{
	long int	ret;
	long int	max;
	int			neg;
	int			i;

	i = 0;
	ret = 0;
	neg = 1;
	while (c[i] == 32 || (c[i] >= 9 && c[i] <= 13))
		i++;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
			neg = -1;
		i++;
	}
	max = LONG_MAX / 10;
	while (ft_isdigit(c[i]))
	{
		if (ret > max || (ret = ret * 10 + c[i] - '0') < 0)
			return (neg == 1 ? -1 : 0);
		i++;
	}
	return (ret * neg);
}
