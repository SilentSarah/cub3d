/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:43:53 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/24 18:14:42 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"
#include "../INCLUDES/raycast.h"

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
		hook_functions(mlx);
	}
	return (0);
}
