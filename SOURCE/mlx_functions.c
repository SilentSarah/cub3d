/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:27:19 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/17 19:29:42 by hmeftah          ###   ########.fr       */
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
	(*mlx)->pinfo = ft_malloc(sizeof(t_pinfo));
	if (!(*mlx)->data || !(*mlx)->pinfo)
	{
		ft_malloc(-1);
		exit (1);
	}
	(*mlx)->mlx = mlx_init(WIN_X, WIN_Y, "CUB3D", true);
	if (!(*mlx)->mlx)
	{
		ft_malloc(-1);
		exit (1);
	}
	(*mlx)->data->cnf = NULL;
	(*mlx)->data->map = NULL;
}

void	set_angle(t_map *mlx, float x, float y)
{
	if (mlx->data->map[(int)y][(int)x] == 'N')
		mlx->pinfo->angle = 0;
	else if (mlx->data->map[(int)y][(int)x] == 'S')
		mlx->pinfo->angle = 270;
	else if (mlx->data->map[(int)y][(int)x] == 'W')
		mlx->pinfo->angle = 180;
	else if (mlx->data->map[(int)y][(int)x] == 'E')
		mlx->pinfo->angle = 360;
}

void	hook_functions(t_map *mlx)
{
	mlx->image = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
	set_angle(mlx, mlx->pinfo->pos_x, mlx->pinfo->pos_y);
	draw_2d_map(mlx);
	mlx_loop_hook(mlx->mlx, &key_handler, mlx);
	mlx_loop(mlx->mlx);
}
