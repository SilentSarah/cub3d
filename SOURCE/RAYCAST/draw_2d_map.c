/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:34:51 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/19 19:22:47 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/raycast.h"

int	get_rgb(t_rgb r, t_rgb g, t_rgb b, float tr)
{
	int	result;

	result = r << 24 | g << 16 | b << 8 | (int)(tr * 255);
	return (result);
}

void	print_2d_box(int x, int y, int rgb, t_map *data)
{
	int	iy;
	int	ix;

	iy = R_Y + 1;
	while (--iy > 0)
	{
		ix = R_X + 1;
		while (--ix > 0)
			mlx_put_pixel(data->image, x + ix, y + iy, rgb);
	}
}
#include <stdio.h>
void	find_xy(float *x, float *y, float fov, t_map *mlx)
{
	float f;
	float px, py;

	f = 0.0;
	py = mlx->pinfo->pos_y;
	px = mlx->pinfo->pos_x;
	fov = convert_to_degree(fov);
	while (mlx->data->map[(int)floor(py + f * cos(fov))][(int)floor(px + f * sin(fov))] != '1')
		f += 0.005;
	*x = px + f * sin(fov);
	*y = py + f * cos(fov);
}

void	raycast(t_map *mlx)
{
	int	i;
	float	f_min, x, y;

	i = -1;
	x = mlx->pinfo->pos_x;
	y = mlx->pinfo->pos_y;
	f_min = mlx->pinfo->angle - (FOV / 2);
	while (++i < WIN_X)
	{
		printf("Current Line Angle: %f, Player Angle: %f\n", f_min, mlx->pinfo->angle);
		find_xy(&x, &y, f_min, mlx);
		drawLine(mlx->image, mlx->pinfo->pos_x * R_X, mlx->pinfo->pos_y * R_Y, x * R_X, y * R_Y);
		f_min += (float)FOV / (float)WIN_X;
	}
}


void	draw_player(t_map *mlx)
{
	int	xy[2];

	xy[0] = (mlx->pinfo->pos_y * R_Y) + 25 * cos(convert_to_degree(mlx->pinfo->angle));
	xy[1] = (mlx->pinfo->pos_x * R_X) + 25 * sin(convert_to_degree(mlx->pinfo->angle));
	raycast(mlx);
	//drawLine(mlx->image, mlx->pinfo->pos_x * R_X, mlx->pinfo->pos_y * R_Y, (int)xy[1], (int)xy[0]);
}

bool	draw_2d_map(t_map *mlx)
{
	int	pos[2];

	pos[0] = -1;
	while (mlx->data->map[++pos[0]])
	{
		pos[1] = -1;
		while (mlx->data->map[pos[0]][++pos[1]])
		{
			if (ft_strchr(" 0\t", mlx->data->map[pos[0]][pos[1]]))
				print_2d_box(pos[1] * R_X , pos[0] * R_Y,
					get_rgb(0, 0, 0, 1), mlx);
			else if (mlx->data->map[pos[0]][pos[1]] == '1')
				print_2d_box(pos[1] * R_X, pos[0] * R_Y,
					get_rgb(255, 255, 255, 1), mlx);
			if (ft_strchr("NSWE", mlx->data->map[pos[0]][pos[1]]))
				mlx->data->map[pos[0]][pos[1]] = '0';
		}
	}
	draw_player(mlx);
	return (0);
}
