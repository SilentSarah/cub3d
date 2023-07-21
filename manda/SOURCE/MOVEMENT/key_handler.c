/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:00:44 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/21 10:44:20 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	key_right(t_map *doom)
{
	double	xtemp;
	double	ytemp;

	xtemp = 0;
	ytemp = 0;
	ytemp = doom->cent_y + cos(-doom->pa) * 5;
	xtemp = doom->cent_x + sin(-doom->pa) * 5;
	if (doom->data->map[(int)ytemp / 40][(int)xtemp / 40] != '1')
	{
		if ((int)xtemp / 40 != (int)doom->cent_x / 40 && (int)ytemp / 40
			!= (int)doom->cent_y / 40 && doom->data->map[(int)ytemp / 40][(int)
			doom->cent_x / 40] == '1' && doom->data->map[(int)doom->cent_y /
			40][(int)xtemp / 40] == '1')
			return ;
		doom->cent_x = xtemp;
		doom->cent_y = ytemp;
	}
}

void	key_left(t_map *doom)
{
	double	xtemp;
	double	ytemp;

	xtemp = 0;
	ytemp = 0;
	ytemp = doom->cent_y - cos(-doom->pa) * 5;
	xtemp = doom->cent_x - sin(-doom->pa) * 5;
	if (doom->data->map[(int)ytemp / 40][(int)xtemp / 40] != '1')
	{
		if ((int)xtemp / 40 != (int)doom->cent_x / 40 && (int)ytemp / 40
			!= (int)doom->cent_y / 40 && doom->data->map[(int)ytemp / 40][(int)
			doom->cent_x / 40] == '1' && doom->data->map[(int)doom->cent_y /
			40][(int)xtemp / 40] == '1')
			return ;
		doom->cent_x = xtemp;
		doom->cent_y = ytemp;
	}
}

void	turn_right(t_map *doom)
{
	doom->pa -= 0.05;
	if (doom->pa <= 0)
		doom->pa += 2 * M_PI;
	doom->px = cos(doom->pa) * 40;
	doom->py = sin(doom->pa) * 40;
}

void	turn_left(t_map *doom)
{
	doom->pa += 0.05;
	if (doom->pa >= 2 * M_PI)
		doom->pa -= 2 * M_PI;
	doom->px = cos(doom->pa) * 40;
	doom->py = sin(doom->pa) * 40;
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
	else if (keydata.key == MLX_KEY_S)
		key_down(doom);
	if (keydata.key == MLX_KEY_D)
		key_right(doom);
	else if (keydata.key == MLX_KEY_A)
		key_left(doom);
	if (keydata.key == MLX_KEY_LEFT)
		turn_right(doom);
	else if (keydata.key == MLX_KEY_RIGHT)
		turn_left(doom);
}
