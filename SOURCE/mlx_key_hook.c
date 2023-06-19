/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:33:17 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/19 17:55:10 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"
#include "../INCLUDES/raycast.h"
#include <stdio.h>

void	move_player(int	direction, t_pinfo *pinfo, char **map)
{
	float	x, y;

	if (direction == FORWARD)
	{
		y = pinfo->pos_y + SPEED * cos(convert_to_degree(pinfo->angle));
		x = pinfo->pos_x + SPEED * sin(convert_to_degree(pinfo->angle));
		if (map[(int)floor(y)][(int)floor(x)] == '1')
		{
			pinfo->pos_y -= SPEED * cos(convert_to_degree(pinfo->angle));
			pinfo->pos_x -= SPEED * sin(convert_to_degree(pinfo->angle));
		}
		else
		{
			pinfo->pos_y = y;
			pinfo->pos_x = x;
		}
	}
	else if (direction == BACKWARD)
	{
		y = pinfo->pos_y - SPEED * cos(convert_to_degree(pinfo->angle));
		x = pinfo->pos_x - SPEED * sin(convert_to_degree(pinfo->angle));
		if (map[(int)floor(y)][(int)floor(x)] == '1')
		{
			pinfo->pos_y += SPEED * cos(convert_to_degree(pinfo->angle));
			pinfo->pos_x += SPEED * sin(convert_to_degree(pinfo->angle));
		}
		else
		{
			pinfo->pos_y = y;
			pinfo->pos_x = x;
		}
	}
}

void	rotate_player(int strafe, t_pinfo *pinfo)
{
	if (strafe == LEFT)
	{
		pinfo->angle += ROT_SPEED;
		if (pinfo->angle > 360)
			pinfo->angle = 0;
	}
	else if (strafe == RIGHT)
	{
		pinfo->angle -= ROT_SPEED;
		if (pinfo->angle < 0)
			pinfo->angle = 360;
	}
}

void	key_handler(void *arg)
{
	t_map	*mlx;

	mlx = arg;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_W))
		move_player(FORWARD, mlx->pinfo, mlx->data->map);
	else if (mlx_is_key_down(mlx->mlx, MLX_KEY_S))
		move_player(BACKWARD, mlx->pinfo, mlx->data->map);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_D))
		rotate_player(RIGHT, mlx->pinfo);
	else if (mlx_is_key_down(mlx->mlx, MLX_KEY_A))
		rotate_player(LEFT, mlx->pinfo);
	//printf("Angle: %f, PosX: %f, PosY: %f\n", mlx->pinfo->angle, mlx->pinfo->pos_x, mlx->pinfo->pos_y);
	draw_2d_map(mlx);
}
