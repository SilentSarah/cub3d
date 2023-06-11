/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:01:41 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/11 18:05:07 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/parse.h"

char	*concatinate(char *s1, char *s2)
{
	int		len;
	char	*res;

	if (!s1)
	{
		s1 = ft_malloc(1, 0, ALLOC, 0);
		ft_bzero(s1, 0);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	res = ft_malloc(len + 1, 0, ALLOC, 0);
	if (!res)
		return (0);
	ft_strlcat(res, s1, len);
	ft_strlcat(res, s2, len);
	return (res);
}

char	*substring(char str, unsigned int s, unsigned int size)
{
	char	*res;

	if (!str || s > size)
		return (0);
	if (size > ft_strlen(str))
		size = ft_strlen(str);
	res = ft_malloc(size + 1, 0, ALLOC, 0);
	if (!res)
		return (0);
	ft_strlcpy(res, str + s, (size - s) + 1);
	return (res);
}
