/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:33:51 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/14 20:03:59 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/parse.h"

char	**datasplit_cnf(char *start, char *end)
{
	end[0] = '\0';
	return (ft_split(start, '\n'));
}

void	copy_data(char *res, char *string)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (string[++i])
	{
		if (ft_isalpha(string[i]))
			continue ;
		if (string[i] > 32)
			res[j++] = string[i];
	}
	res[j] = '\0';
}

bool	extract_values(char *string, int *choice)
{
	char	**split;
	char	*res;
	int		j;
	int		i;

	i = -1;
	j = 0;
	res = ft_malloc(ft_strlen(string));
	if (!res)
		return (1);
	copy_data(res, string);
	split = ft_split(res, ',');
	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		choice[i] = ft_atoi(split[i]);
		free (split[i++]);
	}
	free (split);
	return (0);
}

bool	extract_map_data(t_cnf *data)
{
	data->cnf = datasplit_cnf(data->cnf_start, data->map_start);
	if (!data->cnf)
		return (1);
	if (set_cnf_data(data->textures, data->f_value, data->c_value, data->cnf))
		return (1);
	// data->map = datasplit_map(data->map_start);
	// if (!data->map)
	// 	return (1);
	return (false);
}
