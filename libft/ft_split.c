/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:28:48 by hmeftah           #+#    #+#             */
/*   Updated: 2022/10/14 18:15:13 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// Used to count how many delimiters by checking if the character
// In front of it is != delimiter
static size_t	countdelims(char const *s, char c)
{
	size_t	word;

	word = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			word++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (word);
}

static void	splitter(char const *s, char c, char **string)
{
	size_t	i;
	size_t	j;
	size_t	delcount;
	size_t	delamount;

	delamount = countdelims(s, c);
	delcount = 0;
	i = 0;
	j = 0;
	while (delcount < delamount)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i - 1] == c)
			j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		string[delcount++] = ft_substr(s, j, i - j);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	size_t	delamount;

	if (!s)
		return (NULL);
	delamount = countdelims(s, c);
	string = ft_calloc(delamount + 1, sizeof(char *));
	if (!(string))
		return (NULL);
	splitter(s, c, string);
	return (string);
}
