/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:43:01 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/11 17:08:47 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	counter = 0;
	if (s != NULL)
	{
		while (*s)
		{
			counter += ft_putchar_fd(*s, fd);
			s++;
		}
	}
	else
		counter += ft_putstr_fd("(null)", fd);
	return (counter);
}
