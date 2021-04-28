/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:19:47 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/28 16:20:52 by lorenuar         ###   ########.fr       */
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
	unsigned long	nbr;
	char			*s;

	(void)str;
	nbr = (unsigned long)va_arg(*args, unsigned long);
DE(args);
DM(INPUT,nbr);

	s = ulongtohex(nbr, data);
	data_debug(data);
	D_STR_DETAILS(s);
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
DE(args);
	if (!(arg_x(NULL, data, args)))
		return (FALSE);
	return (TRUE);
}