/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:17:11 by hassimi           #+#    #+#             */
/*   Updated: 2023/07/21 15:59:33 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

int	hardecode_part2(int rvy, int rvx, double ra, t_map *doom)
{
	if (ra <= M_PI && ra >= M_PI / 2)
	{
		if ((rvy > 0 && rvy < (doom->map_width - 80)) && (rvx > 0
				&& rvy < (doom->map_hight - 80)))
		{
			if (doom->data->map[rvy / 40][rvx / 40 +1] == '1'
				&& doom->data->map[rvy / 40 -1][rvx / 40] == '1')
				return (1);
		}
	}
	else if (ra <= M_PI / 2 && ra >= 0)
	{
		if ((rvy > 0 && rvy < (doom->map_width - 80))
			&& (rvx > 0 && rvy < (doom->map_hight - 80)))
		{
			if (doom->data->map[rvy / 40][rvx / 40 -1] == '1'
				&& doom->data->map[rvy / 40 - 1][rvx / 40] == '1')
				return (1);
		}
	}
	return (0);
}

int	hardcode(int rvy, int rvx, double ra, t_map *doom)
{
	if (ra <= 2 * M_PI && ra >= (M_PI + (M_PI / 2)))
	{
		if ((rvy > 0 && rvy < (doom->map_width - 80)) && (rvx > 0 && rvy
				< (doom->map_hight - 80)))
		{
			if (doom->data->map[rvy / 40 + 1][rvx / 40] == '1'
				&& doom->data->map[rvy / 40][rvx / 40 - 1] == '1')
				return (1);
		}
	}
	else if (ra <= (M_PI + (M_PI / 2)) && ra > M_PI)
	{
		if ((rvy > 0 && rvy < (doom->map_width - 80)) && (rvx > 0 && rvy
				< (doom->map_hight - 80)))
		{
			if (doom->data->map[rvy / 40][rvx / 40 + 1] == '1'
				&& doom->data->map[rvy / 40 + 1][rvx / 40] == '1')
				return (1);
		}
	}
	else
		if (hardecode_part2(rvy, rvx, ra, doom) == 1)
			return (1);
	return (0);
}

// -----------------------------------------------------------------------------
void	assigning(t_map *doom)
{
	doom->cent_x = (doom->pinfo->pos_x * 40) + 20;
	doom->cent_y = (doom->pinfo->pos_y * 40) + 20;
	doom->map_hight = (40 * (doom->doom_hight));
	if (doom->map_hight < 440)
		doom->map_hight = 440;
	doom->map_width = (40 * (doom->doom_width));
	if (doom->map_width < 640)
		doom->map_width = 640;
	doom->map_s = 0.2;
	doom->dr = M_PI / 180;
	if (doom->data->map[(int)doom->pinfo->pos_y][(int)doom->pinfo->pos_x] ==
		'N')
		doom->pa = M_PI + M_PI_2;
	if (doom->data->map[(int)doom->pinfo->pos_y][(int)doom->pinfo->pos_x] ==
		'S')
		doom->pa = M_PI_2;
	if (doom->data->map[(int)doom->pinfo->pos_y][(int)doom->pinfo->pos_x] ==
		'W')
		doom->pa = M_PI;
	if (doom->data->map[(int)doom->pinfo->pos_y][(int)doom->pinfo->pos_x] ==
		'E')
		doom->pa = 2 * M_PI;
	doom->px = cos(doom->pa) * 40;
	doom->py = sin(doom->pa) * 40;
}

void	drawray(t_map *doom)
{
	t_ray	r;
	int		i;

	i = 0;
	r.ra = doom->pa - doom->dr * 30;
	if (r.ra < 0)
		r.ra += 2 * M_PI;
	if (r.ra > 2 * M_PI)
		r.ra -= 2 * M_PI;
	while (i < 640)
	{
		calculating(&r, doom);
		project(&r, doom, i);
		i++;
		r.ra += (doom->dr * 60) / 640;
		if (r.ra < 0)
			r.ra += 2 * M_PI;
		if (r.ra > 2 * M_PI)
			r.ra -= 2 * M_PI;
	}
}

int	raycasting(t_map *doom)
{
	assigning(doom);
	doom->image1 = mlx_new_image(doom->mlx, doom->map_width + 40,
			doom->map_hight + 40);
	mlx_image_to_window(doom->mlx, doom->image1, 0, 0);
	mlx_key_hook(doom->mlx, &ft_hook, doom);
	mlx_loop_hook(doom->mlx, ft_randering, doom);
	mlx_loop(doom->mlx);
	mlx_terminate(doom->mlx);
	return (EXIT_SUCCESS);
}
