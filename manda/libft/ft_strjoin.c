/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:31:57 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/20 18:28:03 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		maxlen;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	maxlen = ft_strlen(s1) + ft_strlen(s2);
	string = (char *)malloc(maxlen + 1);
	if (!(string))
		return (ft_calloc(sizeof(char), 1));
	while (*s1 != '\0')
		*string++ = *s1++;
	while (*s2 != '\0')
		*string++ = *s2++;
	*string = '\0';
	return (string - maxlen);
}
