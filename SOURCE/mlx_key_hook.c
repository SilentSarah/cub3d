/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:33:17 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/17 19:58:57 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"
#include "../INCLUDES/raycast.h"
#include <stdio.h>

void	move_player(int	direction, t_pinfo *pinfo)
{
	float	pos_x;
	float	pos_y;

	
	if (direction == FORWARD)
	{
		pos_x = pinfo->pos_x - SPEED * sin(convert_to_degree(pinfo->angle));
		pos_y = pinfo->pos_y - SPEED * cos(convert_to_degree(pinfo->angle));
		pinfo->pos_y = pos_y;
		pinfo->pos_x = pos_x;
	}
	else if (direction == BACKWARD)
	{
		pos_x = pinfo->pos_x + SPEED * sin(convert_to_degree(pinfo->angle));
		pos_y = pinfo->pos_y + SPEED * cos(convert_to_degree(pinfo->angle));
		pinfo->pos_y = pos_y;
		pinfo->pos_x = pos_x;
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
		move_player(FORWARD, mlx->pinfo);
	else if (mlx_is_key_down(mlx->mlx, MLX_KEY_S))
		move_player(BACKWARD, mlx->pinfo);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_D))
		rotate_player(RIGHT, mlx->pinfo);
	else if (mlx_is_key_down(mlx->mlx, MLX_KEY_A))
		rotate_player(LEFT, mlx->pinfo);
	printf("Angle: %f, PosX: %f, PosY: %f\n", mlx->pinfo->angle, mlx->pinfo->pos_x, mlx->pinfo->pos_y);
	draw_2d_map(mlx);
}
