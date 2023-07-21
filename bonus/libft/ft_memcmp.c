/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:22:46 by hmeftah           #+#    #+#             */
/*   Updated: 2022/10/13 15:30:26 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*sd;

	i = 0;
	s = (unsigned char *)s1;
	sd = (unsigned char *)s2;
	while (i < n)
	{
		if (s[i] != sd[i])
			return ((s[i]) - sd[i]);
		i++;
	}
	return (0);
}
