/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:05:31 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/15 18:20:58 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (1);
	return (0);
}

bool	find_double_newlines(char *start_map)
{
	int	i;

	i = -1;
	while (start_map[++i])
		if (start_map[i] == '\n' && start_map[i + 1] == '\n')
			return (1);
	return (0);
}

bool	parse_map(t_cnf *data, char **map)
{
	if (check_inv_elements(map) || test_map_walls(data))
		return (1);
	return (0);
}
