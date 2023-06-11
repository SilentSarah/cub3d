/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:20:53 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/11 17:06:54 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "ft_printf.h"

static int	print_long(unsigned long i, int counter, int fd)
{
	if (i < 16)
		counter += ft_putchar_fd("0123456789abcdef"[i % 16], fd);
	else
	{
		counter = print_long(i / 16, counter, fd);
		counter = print_long(i % 16, counter, fd);
	}
	return (counter);
}

int	ft_putadress(void *ptr, int fd)
{	
	long	i;
	int		counter;

	counter = 0;
	i = (unsigned long)ptr;
	counter += ft_putstr_fd("0x", fd);
	counter = print_long(i, counter, fd);
	return (counter);
}
