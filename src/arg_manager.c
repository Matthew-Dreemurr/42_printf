/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:10:37 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/06 12:35:25 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	arg_c(t_data *data, va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	if (data->min_width && !data->minus)
		width_print(data->min_width, 1, &(*data));
	ft_putchar(c, &(*data));
	data->skip++;
	if (data->min_width && data->minus)
		width_print(data->min_width, 1, &(*data));
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
		data->min_width = (int)va_arg(*args, int);
	str = (const char *)va_arg(*args, const char * );
	if (str && *str)
		len = len_str(str);
	else
		len = len_str(STR_NULL);
	if (data->min_width && !data->minus)
		width_print(data->min_width, len, &(*data));
	if (!str || !*str)
		ft_putstr(STR_NULL, &(*data));
	else
		ft_putstr(str, &(*data));
	if (data->min_width && data->minus)
		width_print(data->min_width, len, &(*data));
	data->skip++;
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
		data->min_width = (int)va_arg(*args, int);
	nbr = (int)va_arg(*args, int);
	len = len_int(nbr);
	if (data->min_width && !data->minus)
		width_print(data->min_width, len, &(*data));
	if (!(print_int(nbr, &(*data))))
		return (ERR);
	if (data->min_width && data->minus)
		width_print(data->min_width, len, &(*data));
	data->skip++;
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
	ptr = (void*)va_arg(*args, void *);
	str = ulongtohex((unsigned long)ptr, &(*data));
	if (!str)
		return (ERR);
	len = len_str(str);
	if (ptr == NULL)
		len = len_str(ADDR_NULL);
	else
		len += 2;
	if (data->min_width && !data->minus)
		width_print(data->min_width, len, &(*data));
	if (ptr == NULL)
		ft_putstr(ADDR_NULL, &(*data));
	else
	{
		data->ret += write(1, "0x", 2);
		putstr_rev(str, &(*data));
	}
	if (data->min_width && data->minus)
		width_print(data->min_width, len, &(*data));
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
	nbr = (unsigned long)va_arg(*args, unsigned long);
	str = ulongtohex(nbr, &(*data));
	if (!str)
		return (ERR);
	len = len_str(str);
	if (data->min_width && !data->minus)
		width_print(data->min_width, len, &(*data));
	putstr_rev(str, *(&data));
	if (data->min_width && data->minus)
		width_print(data->min_width, len, &(*data));
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