/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:14:09 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/19 15:48:35 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
#include "include/debug_utils.h"
#include "include/wraloc.h"

#define ARG1 "%8.3x", 8375
int	main(void)
{
	int	ret;

	write(1, "{\0", 2);
	ret = printf(ARG1);
	puts("}");
	printf("ret [%d]\n", ret);
	puts("");
	ret = 0;
	write(1, "{\0", 2);
	ret = ft_printf(ARG1);
	puts("}");
	printf("ret [%d]\n", ret);
	return (0);
}
