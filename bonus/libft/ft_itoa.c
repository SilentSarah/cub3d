/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:14:49 by hmeftah           #+#    #+#             */
/*   Updated: 2022/10/14 17:45:42 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoabrain(long num, int count, int n)
{
	char	*ptr;

	num = n;
	ptr = (char *)malloc(count + 1);
	if (!(ptr))
		return (NULL);
	if (num < 0)
	{
		ptr[0] = '-';
		num = -num;
	}
	ptr[count] = '\0';
	while (--count >= 0)
	{
		if (count == 0 && n < 0)
			break ;
		ptr[count] = num % 10 + '0';
		num = num / 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	long	num;
	int		count;
	char	*ptr;

	if (n == 0)
	{
		ptr = ft_calloc(2, sizeof(char));
		ptr[0] = '0';
		return (ptr);
	}
	num = n;
	count = 0;
	if (num < 0)
	{
		count++;
		num = -n;
	}
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (ft_itoabrain(num, count, n));
}
