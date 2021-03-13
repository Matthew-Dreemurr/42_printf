/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:23:53 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/25 12:10:15 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cpy_s1;
	const unsigned char	*cpy_s2;
	size_t				i;

	i = 0;
	cpy_s1 = s1;
	cpy_s2 = s2;
	while (i < n)
	{
		if ((cpy_s1[i] != cpy_s2[i]))
			return (cpy_s1[i] - cpy_s2[i]);
		i++;
	}
	return (0);
}
