/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:46:45 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/21 14:27:32 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	free_2d_array(char	**ptr)
{
	int	i;

	i = -1;
	if (!ptr)
		return ;
	while (ptr[++i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
	}
	free (ptr);
}

void	print_map_cnf(t_cnf *data)
{
	int		i;
	char	*type;

	i = -1;
	while (data->textures[++i])
	{
		if (i == NO)
			type = "NO";
		else if (i == SO)
			type = "SO";
		else if (i == WE)
			type = "WE";
		else if (i == EA)
			type = "EA";
		ft_printf(1, "[%s] [Path]: %s\n", type, data->textures[i]);
	}
	ft_printf(1, "[F] [R: %d, G: %d, B: %d]\n", data->f_value[0],
		data->f_value[1], data->f_value[2]);
	ft_printf(1, "[C] [R: %d, G: %d, B: %d]\n", data->c_value[0],
		data->c_value[1], data->c_value[2]);
	i = -1;
	while (data->map[++i])
		ft_printf(1, "%s\n", data->map[i]);
}

char	*add_spaces(char *map_el, int b_len)
{
	int		i;
	char	*res;

	res = ft_malloc(b_len + 1);
	if (!res)
		return (NULL);
	i = ft_strlcpy(res, map_el, b_len + 1);
	while (i < b_len)
		res[i++] = ' ';
	res[i] = '\0';
	return (res);
}

int	find_len(char **map, t_map *mlx)
{
	int		i;
	size_t	b_len;

	i = -1;
	b_len = 0;
	while (map[++i])
		if (ft_strlen(map[i]) > b_len)
			b_len = ft_strlen(map[i]);
	mlx->doom_hight = i - 1;
	mlx->doom_width = b_len;
	return (b_len);
}

char	**add_padding(char **map, t_map *mlx)
{
	int		i;
	char	**new_map;
	size_t	max_len;

	i = -1;
	max_len = find_len(map, mlx);
	new_map = (char **)ft_malloc(sizeof(char *) * mlx->doom_hight + 3);
	if (!new_map)
	{
		free_2d_array(map);
		return (NULL);
	}
	while (map[++i])
		new_map[i] = add_spaces(map[i], max_len);
	new_map[i] = NULL;
	free_2d_array(map);
	return (new_map);
}
