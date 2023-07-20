/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 01:02:45 by hmeftah           #+#    #+#             */
/*   Updated: 2022/10/13 15:32:37 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	size_t	i;
	size_t	maxpos;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	maxpos = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (s1[i] == '\0')
		return (ft_calloc(sizeof(char), 1));
	while (ft_strchr(set, s1[maxpos]))
		maxpos--;
	string = ft_substr(s1, i, maxpos - i + 1);
	return (string);
}
