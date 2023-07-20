/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:43:53 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/20 12:19:24 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	main(int ac, char **av)
{
	t_map	*mlx;
	if (ac == 2)
	{
		initialize_mlx(&mlx);
		if (load_map(av[1], mlx->data))
		{
			ft_malloc(-1);
			exit (1);
		}
		if (extract_map_data(mlx, mlx->data))
		{
			free_2d_array(mlx->data->cnf);
			free_2d_array(mlx->data->map);
			ft_malloc(-1);
			exit (1);
		}
		load_textures(mlx);
		raycasting(mlx);
	}

	return (0);
}