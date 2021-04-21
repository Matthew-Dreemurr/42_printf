/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:10:49 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/21 17:26:41 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**
*/

int	arg_d(const char *str, t_data *data, va_list *args)
{
	int nbr;

	(void)str;
	if (data->arg)
		data->fill = (int)va_arg(*args, int);
	nbr = (int)va_arg(*args, int);
	return (TRUE);
}

/*
**
*/

int	arg_u(const char *str, t_data *data, va_list *args)
{
	unsigned int	nbr;

	(void)str;
	if (data->arg)
		data->fill = (int)va_arg(*args, int);
	nbr = (unsigned int)va_arg(*args, unsigned int);
	(void)nbr;
	return (TRUE);
}

/*
**
*/