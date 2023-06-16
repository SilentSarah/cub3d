/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:27:19 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/16 15:09:08 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"
#include "../INCLUDES/raycast.h"

void	initialize_mlx(t_map **mlx)
{
	*mlx = ft_malloc(sizeof(t_map));
	if (!*mlx)
		return (exit(1));
	(*mlx)->data = ft_malloc(sizeof(t_cnf));
	if (!(*mlx)->data)
	{
		ft_malloc(-1);
		exit (1);
	}
	(*mlx)->data->cnf = NULL;
	(*mlx)->data->map = NULL;
	(*mlx)->data->x = 0;
	(*mlx)->data->y = 0;
	(*mlx)->mlx = mlx_init(WIN_X, WIN_Y, "CUB3D", true);
	if (!(*mlx)->mlx)
	{
		ft_malloc(-1);
		exit (1);
	}
	(*mlx)->image = mlx_new_image((*mlx)->mlx, WIN_X, WIN_Y);
}

void	hook_functions(t_map *mlx)
{
	mlx_loop_hook(mlx->mlx, &key_handler, mlx);
	mlx_loop(mlx->mlx);
}
