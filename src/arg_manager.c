/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:10:37 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/07 13:32:49 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	arg_c(t_data *data, va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);

	return (TRUE);
}

/*
**   if `str` is null len = 6 (len_str("(null)"))
*/

int	arg_s(t_data *data, va_list *args)
{
	const char	*str;
	size_t		len;

	if (data->arg)
		data->width = (int)va_arg(*args, int);
	str = (const char *)va_arg(*args, const char * );

	return (TRUE);
}

/*
**
*/

int	arg_d(t_data *data, va_list *args)
{
	size_t len;
	int nbr;

	if (data->arg)
		data->width = (int)va_arg(*args, int);
	nbr = (int)va_arg(*args, int);

	return (TRUE);
}

/*
**
*/

int	arg_u(t_data *data, va_list *args)
{
	size_t			len;
	unsigned int	nbr;

	if (data->arg)
		data->width = (int)va_arg(*args, int);
	nbr = (unsigned int)va_arg(*args, unsigned int);

	return (TRUE);
}

/*
**
*/

int	arg_p(t_data *data, va_list *args)
{
	void	*ptr;
	char	*str;
	size_t	len;

	data->skip++;
	if (data->arg)
		data->width = (int)va_arg(*args, int);
	ptr = (void*)va_arg(*args, void *);
	str = ulongtohex((unsigned long)ptr, &(*data));
	if (!str)
		return (ERR);
	free(str);
	return (TRUE);
}

/*
**
*/

int	arg_x(t_data *data, va_list *args)
{
	unsigned long	nbr;
	char			*str;
	size_t			len;

	data->skip++;
	if (data->arg)
		data->width = (int)va_arg(*args, int);
	nbr = (unsigned long)va_arg(*args, unsigned long);
	str = ulongtohex(nbr, &(*data));
	if (!str)
		return (ERR);

	free(str);
	return (TRUE);
}

/*
**
*/

int	arg_x_up(t_data *data, va_list *args)
{
	data->x_up++;
	if (!(arg_x(&(*data), &(*args))))
		return (FALSE);
	return (TRUE);
}