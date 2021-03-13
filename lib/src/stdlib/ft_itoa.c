/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:19:23 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/15 13:39:38 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	check_len(unsigned int n)
{
	int		size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	char			*ret;
	int				size;
	int				isneg;
	unsigned int	num;

	isneg = 0;
	if (n <= 0 && ++isneg)
		num = n * -1;
	else
		num = n;
	size = check_len(num);
	if (!(ret = malloc(sizeof(char) * (size + isneg + 1))))
		return (NULL);
	ft_bzero(ret, size + isneg + 1);
	while (num)
	{
		ret[--size + isneg] = (num % 10) + '0';
		num /= 10;
	}
	if (isneg)
		ret[0] = '-';
	if (!n)
		ret[0] = '0';
	return (ret);
}
