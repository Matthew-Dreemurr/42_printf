/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:09:43 by mhadad            #+#    #+#             */
/*   Updated: 2020/12/25 12:37:48 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*cpy_s1;
	const unsigned char	*cpy_s2;
	size_t				i;

	i = 0;
	cpy_s1 = (const unsigned char	*)s1;
	cpy_s2 = (const unsigned char	*)s2;
	while (i < n)
	{
		if ((!cpy_s1[i] || cpy_s1[i] != cpy_s2[i]))
			return (cpy_s1[i] - cpy_s2[i]);
		i++;
	}
	return (0);
}
