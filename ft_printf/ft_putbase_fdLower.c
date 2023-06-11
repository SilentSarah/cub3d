/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fdLower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:20:53 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/11 17:07:32 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "ft_printf.h"

int	ft_putbase_fd_lower(unsigned int n, int fd)
{
	int	counter;

	counter = 0;
	if (n < 16)
	{
		counter += ft_putchar_fd("0123456789abcdef"[n % 16], fd);
	}
	else if (n <= 9)
		counter += ft_putbase_fd_lower(n, fd);
	else
	{
		counter += ft_putbase_fd_lower(n / 16, fd);
		counter += ft_putbase_fd_lower(n % 16, fd);
	}
	return (counter);
}
