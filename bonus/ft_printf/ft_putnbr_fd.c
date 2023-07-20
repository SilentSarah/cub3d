/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:03:22 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/11 17:08:33 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	number;
	int		counter;

	counter = 0;
	number = (long)n;
	if (number == -2147483648)
		counter = ft_putstr_fd("-2147483648", fd);
	else if (number < 0)
	{
		counter += ft_putchar_fd('-', fd);
		counter += ft_putnbr_fd(-number, fd);
	}
	else if (number >= 10)
	{
		counter += ft_putnbr_fd(number / 10, fd);
		counter += ft_putnbr_fd(number % 10, fd);
	}
	else
	{
		counter += ft_putchar_fd(number + '0', fd);
	}
	return (counter);
}
