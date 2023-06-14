/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader_support.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:10:04 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/14 20:04:54 by hmeftah          ###   ########.fr       */
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
			if (!*r_data)
				return (NULL);
			while (ft_strchr("\t 10", *(r_data + i)))
				i++;
			if (i > 0)
				return (r_data);
		}
		r_data++;
	}
	return (NULL);
}

int	compare_cnf_map(char *raw_data, t_cnf *data)
{
	data->map_start = ft_strchr_set(raw_data, "10");
	data->cnf_start = ft_strnstr_cnf(raw_data);
	if (data->map_start < data->cnf_start)
		return (1);
	if (find_start_of_map(raw_data))
		data->map_start = find_start_of_map(raw_data) - 1;
	else
		data->map_start = NULL;
	if (data->map_start)
		if (ft_strnstr_cnf(data->map_start))
			return (1);
	if (!data->cnf_start || !data->map_start)
		return (1);
	return (0);
}
