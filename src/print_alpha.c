/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:22:24 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/28 15:58:05 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**   Will print the carater `c` and increment `data->skip/ret`
*/

void	ft_putchar(char c, t_data *data)
{
	write(1, &c, 1);
	data->ret++;
}

/*
**   .
*/

void	ft_putstr(const char *s, t_data *data)
{
	size_t	i;
	size_t	max;

	max = data->prec;
	i = 0;
	if (!data->dot)
		max = len_str(s);
	while (s && s[i] && max--)
		write(1, &s[i++], 1);
	data->ret += i;
}

/*
**   .
*/

void	putstr_rev(const char *s, t_data *data)
{
	size_t	len;

	len = len_str(s);
	data->ret += len;
	while (s && len > 0 && s[--len])
		write(1, &(s[len]), 1);
}
