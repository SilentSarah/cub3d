/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:48:01 by hmeftah           #+#    #+#             */
/*   Updated: 2022/10/14 21:45:44 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (*needle == '\0' || haystack == needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (((haystack[i]) != '\0') && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j]
			&& haystack[i + j] != '\0'
			&& needle[j] != '\0' && i + j < len)
			j++;
		if (j == ft_strlen(needle))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
