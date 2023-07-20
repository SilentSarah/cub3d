/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:20:53 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/11 17:07:11 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "ft_printf.h"

int	ft_putbase_fd(unsigned int n, int fd)
{
	int	counter;

	counter = 0;
	if (n < 16)
	{
		counter += ft_putchar_fd("0123456789ABCDEF"[n % 16], fd);
	}
	else if (n <= 9)
		counter += ft_putnbr_fd(n, fd);
	else
	{
		counter += ft_putbase_fd(n / 16, fd);
		counter += ft_putbase_fd(n % 16, fd);
	}
	return (counter);
}
