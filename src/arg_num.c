/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:10:49 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/28 18:07:53 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**   .
*/

int	arg_d(const char *str, t_data *data, va_list *args)
{
	int		nbr;
	char	*s;

	(void)str;
	if (data->arg)
		data->fill = (int)va_arg(*args, int);
	nbr = (int)va_arg(*args, int);
	s = ft_itoa(nbr);
	if (!s)
		return (FALSE);
	print_arg_d(nbr, s, data);
	free(s);
	data->skip++;
	return (TRUE);
}

/*
**   .
*/

int	arg_u(const char *str, t_data *data, va_list *args)
{
	unsigned int		nbr;
	char				*s;

	(void)str;
	if (data->arg)
	{
		data->fill = (int)va_arg(*args, int);

		
	}
	nbr = (unsigned int)va_arg(*args, unsigned int);


	s = uinttochar(nbr);
	if (!s)
		return (FALSE);
	print_arg_d(nbr, s, data);
	free(s);
	data->skip++;
	return (TRUE);
}

/*
**   .
*/