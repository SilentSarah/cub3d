/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader_support.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:10:04 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/13 20:20:36 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/parse.h"

char	*ft_strchr_set(char *string, char *set)
{
	int	i;

	i = -1;
	while (string[++i])
		if (ft_strchr(set, string[i]))
			return (string + i);
	return (NULL);
}

char	*ft_strnstr_cnf(char *raw_data)
{
	int			i;
	static char	*cnfs[7] = {"NO", "SO", "WE", "EA", "F", "C", NULL};

	i = 0;
	while (cnfs[i])
	{
		if (ft_strnstr(raw_data, cnfs[i], ft_strlen(raw_data)))
			return (ft_strnstr(raw_data, cnfs[i], ft_strlen(raw_data)));
		i++;
	}
	return (NULL);
}

char	*find_start_of_map(char *raw_data)
{
	int		i;
	char	*r_data;

	r_data = raw_data;
	while (*r_data)
	{
		i = 0;
		if (*r_data == '\n')
		{
			while (*r_data == '\n')
				r_data++;
			while (ft_strchr("\t 10", *(r_data + i)))
				i++;
			if (i > 0)
				return (r_data);
		}
		r_data++;
	}
	return (NULL);
}

int	compare_cnf_map(char *raw_data)
{
	char		*cnf;
	char		*map;

	cnf = ft_strnstr_cnf(raw_data);
	map = find_start_of_map(raw_data);
	if (map)
		if (ft_strnstr_cnf(map))
			return (1);
	if (!cnf || !map)
		return (1);
	if (map < cnf)
		return (1);
	ft_printf(1, "CNF FOUND: \n%s\n", cnf);
	ft_printf(1, "----------------------------------\n");
	ft_printf(1, "MAP FOUND: \n%s\n", map);
	return (0);
}
