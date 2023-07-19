/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:05:31 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/24 18:26:10 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"
#include "../../INCLUDES/parse.h"

bool	check_inv_elements(char **map)
{
	int	pos[2];
	int	pr[2];

	ft_bzero(pr, 2 * sizeof(int));
	ft_memset(pos, -1, 2 * sizeof(int));
	while (map[++pos[0]])
	{
		pos[1] = -1;
		while (map[pos[0]][++pos[1]])
		{
			if (ft_strchr("NSWE", map[pos[0]][pos[1]]))
				pr[0]++;
			else if (!ft_strchr("10NSWE \t", map[pos[0]][pos[1]]))
				pr[1]++;
		}
	}
	if (pr[0] > 1 || pr[0] < 1 || pr[1] > 0)
	{
		ft_printf(2, "[✘] Invalid Element Placement.\n");
		return (1);
	}
	return (0);
}

bool	find_double_newlines(char *start_map)
{
	int	i;

	i = -1;
	while (start_map[++i])
	{
		if (start_map[i] == '\n' && start_map[i + 1] == '\n')
		{
			ft_printf(2, "[✘] Invalid Map Configuration.\n");
			return (1);
		}
	}
	return (0);
}

bool	parse_map(t_map *mlx, char **map)
{
	ft_printf(1, "[↻] Parsing Map Elements...\n");
	if (check_inv_elements(map))
		return (1);
	if (test_map_walls(mlx->data, mlx->pinfo))
	{
		ft_printf(2, "[✘] Map is open.\n");
		return (1);
	}
	ft_printf(1, "[✔] Map Parsing is complete.\n");
	return (0);
}
