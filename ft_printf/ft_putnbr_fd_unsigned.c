/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:03:22 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/11 17:08:04 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	int	counter;

	counter = 0;
	if (n >= 10)
	{
		counter += ft_putnbr_fd(n / 10, fd);
		counter += ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		counter += ft_putchar_fd(n + '0', fd);
	}
	return (counter);
}
