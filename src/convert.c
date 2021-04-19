/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:16:18 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/19 18:00:58 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

char*	ulongtohex(unsigned long nbr, t_data *data)
{
	char			*index[2];
	char			*ret;
	int				i;

	i = 0;
	index[0] = "0123456789abcdef";
	index[1] = "0123456789ABCDEF";
	ret = (char *)malloc(32);
	if (!ret)
		return (NULL);
	if (!nbr)
		ret[i++] = index[data->x_up][0];
	else
		while (nbr > 0)
		{
			ret[i] = index[data->x_up][nbr % 16];
			nbr /= 16;
			i++;
		}
	ret[i] = '\0';
	return (ret);
}

/*
**
*/

int	chartoi(const char *str, t_data *data)
{
	long	len;
	int		i;
	if (!str)
		return (FALSE);
	i = 0;
	len = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		len *= 10;
		len += (str[i] - '0');
		i++;
	}
	if (len > MAX_INT)
		return (FALSE);
	data->skip += i;
#ifdef DEBUG_TRUE
	BM("chartoi");
	D_LINT(len);
	DE(i);
	D_INT(data->width);
	D_INT(data->skip);
	BR;
#endif
	return (len);
}