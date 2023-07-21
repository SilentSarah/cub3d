/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:16:23 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/21 15:53:26 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	turn_right(t_map *doom)
{
	doom->pa += 0.05;
	if (doom->pa <= 0)
		doom->pa += 2 * M_PI;
	doom->px = cos(doom->pa) * 40;
	doom->py = sin(doom->pa) * 40;
}

void	turn_left(t_map *doom)
{
	doom->pa -= 0.05;
	if (doom->pa >= 2 * M_PI)
		doom->pa -= 2 * M_PI;
	doom->px = cos(doom->pa) * 40;
	doom->py = sin(doom->pa) * 40;
}

void	mous_hook(double xdelta, double ydelta, void *param)
{
	t_map	*doom;

	doom = (t_map *)param;
	if (xdelta < 100)
		turn_left(doom);
	if (xdelta > 100)
		turn_right(doom);
	if (xdelta != 100)
		mlx_set_mouse_pos(doom->mlx, 100, 100);
	if (ydelta != 100)
		mlx_set_mouse_pos(doom->mlx, 100, 100);
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*doom;

	doom = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		free_2d_array(doom->data->cnf);
		ft_malloc(-1);
		exit(0);
	}
	if (keydata.key == MLX_KEY_W)
		key_w(doom);
	if (keydata.key == MLX_KEY_S)
		key_down(doom);
	if (keydata.key == MLX_KEY_D)
		key_right(doom);
	if (keydata.key == MLX_KEY_A)
		key_left(doom);
	if (keydata.key == MLX_KEY_RIGHT)
		turn_right(doom);
	if (keydata.key == MLX_KEY_LEFT)
		turn_left(doom);
}
