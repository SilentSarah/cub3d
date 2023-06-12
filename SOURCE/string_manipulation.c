/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:01:41 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/12 18:48:54 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/parse.h"

char	*_strcpy(char *dst, char *src)
{
	int	i;

	i = -1;
	while (dst && src && src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

char	*_strcat(char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (dst && dst[i])
		i++;
	while (src && src[++j])
		dst[i + j] = src[j];
	dst[i + j] = '\0';
	return (dst);
}

char	*concatinate(char *s1, char *s2)
{
	int		len;
	char	*res;

	if (!s1)
		s1 = "";
	len = ft_strlen(s1) + ft_strlen(s2);
	res = ft_malloc(len + 1);
	if (!res)
		return (0);
	ft_bzero(res, len);
	_strcpy(res, s1);
	_strcat(res, s2);
	return (res);
}

char	*substring(char *str, unsigned int s, unsigned int size)
{
	char	*res;

	if (!str || s > size)
		return (0);
	if (size > ft_strlen(str))
		size = ft_strlen(str);
	res = ft_malloc(size + 1);
	if (!res)
		return (0);
	ft_strlcpy(res, str + s, (size - s) + 1);
	return (res);
}

int	calculate_char(char *string, char c)
{
	int	i;
	int	found;

	i = -1;
	found = 0;
	if (!string)
		return (0);
	while (string[++i])
		if (string[i] == c)
			found++;
	return (found);
}
