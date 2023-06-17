/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:34:51 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/17 19:54:20 by hmeftah          ###   ########.fr       */
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
	print_2d_box(mlx->pinfo->pos_x * R_X, mlx->pinfo->pos_y * R_Y,
		get_rgb(49, 255, 20, 1), mlx);
	//draw_line(mlx->pinfo->pos_x * R_X, mlx->pinfo->pos_y * R_Y, mlx->image);
	return (0);
}
