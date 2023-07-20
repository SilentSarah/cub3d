/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:53:20 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/11 17:05:08 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "includes/libft.h"

static int	printassist(const char c, va_list args, int fd)
{
	int	i;

	i = 0;
	if (c == 'd' || c == 'i')
		i += ft_putnbr_fd(va_arg(args, int), fd);
	else if (c == 'u')
		i += ft_putnbr_fd_unsigned(va_arg(args, unsigned int), fd);
	else if (c == 'c')
		i += ft_putchar_fd(va_arg(args, int), fd);
	else if (c == 's')
		i += ft_putstr_fd(va_arg(args, char *), fd);
	else if (c == '%')
		i += ft_putchar_fd('%', fd);
	else if (c == 'x')
		i += ft_putbase_fd_lower(va_arg(args, unsigned int), fd);
	else if (c == 'X')
		i += ft_putbase_fd(va_arg(args, unsigned int), fd);
	else if (c == 'p')
		i += ft_putadress(va_arg(args, void *), fd);
	return (i);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			i += printassist(*(format + 1), args, fd);
			format ++;
		}
		else
			i += ft_putchar_fd(*format, fd);
		format++;
	}
	va_end(args);
	return (i);
}
