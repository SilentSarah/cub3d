/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:43:53 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/21 15:49:04 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	main(int ac, char **av)
{
	t_map	*mlx;

	if (ac == 2)
	{
		initialize_mlx(&mlx);
		load_handler(mlx, av[1]);
		load_textures(mlx);
		raycasting(mlx);
	}
	return (0);
}
