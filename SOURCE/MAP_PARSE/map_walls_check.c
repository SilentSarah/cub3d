/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:43:42 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/15 18:06:23 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/parse.h"

int	*find_start_pos(char **map)
{
	int	*pos;

	pos = ft_malloc(2 * sizeof(int));
	if (!pos)
		return (NULL);
	ft_bzero(pos, 2 * sizeof(int));
	while (map[pos[0]])
	{
		pos[1] = 0;
		while (map[pos[0]][pos[1]])
		{
			if (ft_strchr("NSWE", map[pos[0]][pos[1]]))
				return (pos);
			pos[1]++;
		}
		pos[0]++;
	}
	ft_bzero(pos, 2 * sizeof(int));
	return (pos);
}

void	flood_map(int x, int y, char **map, t_cnf *data)
{
	if (!map[y])
	{
		data->outside = true;
		return ;
	}
	if (map[y][x] == 'Z' || map[y][x] == '1')
		return ;
	if (map[y][x] <= 32 || x == 0 || y == 0)
	{
		map[y][x] = 'X';
		data->outside = true;
		return ;
	}
	map[y][x] = 'Z';
	flood_map(x + 1, y, map, data);
	flood_map(x - 1, y, map, data);
	flood_map(x, y - 1, map, data);
	flood_map(x, y + 1, map, data);
}

bool	test_map_walls(t_cnf *data)
{
	char	**cpymap;
	int		*pos;

	data->outside = false;
	cpymap = ft_split(data->map_start + 1, '\n');
	if (!cpymap)
		return (1);
	pos = find_start_pos(cpymap);
	if (!pos || (!pos[0] && pos[1]))
		return (1);
	flood_map(pos[1], pos[0], cpymap, data);
	free_2d_array(cpymap);
	return (data->outside);
}
