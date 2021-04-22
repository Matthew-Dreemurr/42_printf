/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:14:09 by mhadad            #+#    #+#             */
/*   Updated: 2021/04/22 16:14:52 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
#include <limits.h>

#define ARG1 "%% *.5i 42 == |% *.5i| ", 4, 42
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
