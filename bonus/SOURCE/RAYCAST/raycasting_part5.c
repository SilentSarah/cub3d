/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_part5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:17:11 by hassimi           #+#    #+#             */
/*   Updated: 2023/07/21 15:34:22 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	rect1(int x, int y, t_map *doom)
{
	int	r;
	int	f;

	r = 0;
	f = 0;
	while (++f < 40)
	{
		r = 0;
		while (++r < 40)
		{
			mlx_put_pixel(doom->image1, (r + (y * 40)) * doom->map_s,
				(f + (x * 40)) * doom->map_s, ft_pixel(255, 255, 255, 255));
		}
	}
}

void	rect(int x, int y, t_map *doom)
{
	int	r;
	int	f;

	r = 0;
	f = 0;
	while (++f < 40)
	{
		r = 0;
		while (++r < 40)
		{
			mlx_put_pixel(doom->image1, (r + (y * 40)) * doom->map_s,
				(f + (x * 40)) * doom->map_s, ft_pixel(0, 0, 0, 255));
		}
	}
}

void	rand_map(t_map *doom)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (doom->data->map[x])
	{
		y = 0;
		while (doom->data->map[x][y])
		{
			if (doom->data->map[x][y] == '1')
				rect(x, y, doom);
			else
				rect1(x, y, doom);
			y++;
		}
		x++;
	}
}
