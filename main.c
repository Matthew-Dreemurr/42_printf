/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:14:09 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/22 15:48:34 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
#include "include/debug_utils.h"
#include "include/wraloc.h"
#define ARG1 "test%%123"

int	main(void)
{
	int	ret;
	ret = printf(ARG1);
	printf(" [%d]\n", ret);
	puts("\n");
	ret = 0;
	ret = ft_printf(ARG1);
	printf(" [%d]\n", ret);
	return (0);
}
