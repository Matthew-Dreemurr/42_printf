/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:19:47 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/28 17:59:30 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**   .
*/

int	arg_p(const char *str, t_data *data, va_list *args)
{
	void	*ptr;
	char	*s;

	(void)str;
	ptr = (void*)va_arg(*args, void *);


	s = ulongtohex((unsigned long)ptr, data);
	if (!s)
		return (ERR);
	print_arg_p(s,data);
	free(s);
	data->skip++;
	return (TRUE);
}

/*
**   .
*/

int	arg_x(const char *str, t_data *data, va_list *args)
{
	unsigned int	nbr;
	char			*s;

	(void)str;
	nbr = (unsigned int)va_arg(*args, int);
	s = ulongtohex(nbr, data);
	if (!s)
		return (ERR);
	print_arg_x(s, data);
	free(s);
	data->skip++;
	return (TRUE);
}

/*
**   .
*/

int	arg_x_up(const char *str, t_data *data, va_list *args)
{
	(void)str;
	data->x_up++;
	if (!(arg_x(NULL, data, args)))
		return (FALSE);
	return (TRUE);
}