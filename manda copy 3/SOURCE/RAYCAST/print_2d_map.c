/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2d_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 10:09:17 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/25 10:23:35 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/raycast.h"

int	get_rgb(t_rgb r, t_rgb g, t_rgb b, float tr)
{
	int	result;

	result = r << 24 | g << 16 | b << 8 | (int)(tr * 255);
	return (result);
}

void	print_2d_box(int x, int y, int rgb, mlx_image_t *image)
{
	int	iy;
	int	ix;

	iy = R_Y + 1;
	while (--iy > 0)
	{
		ix = R_X + 1;
		while (--ix > 0)
			mlx_put_pixel(image, x + ix, y + iy, rgb);
	}
}

void	print_minimap(mlx_image_t *image, char **map, t_pinfo *pinfo)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr(" 0", map[i][j]))
				print_2d_box(j * R_X, i * R_Y, get_rgb(0, 0, 0, 1), image);
			else if (map[i][j] == '1')
				print_2d_box(j * R_X, i * R_Y, get_rgb(255, 255, 255, 1), image);
		}
	}
}