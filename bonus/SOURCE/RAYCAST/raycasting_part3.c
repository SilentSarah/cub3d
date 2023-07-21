/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_part3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:33:17 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/21 15:32:27 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	my_clear(t_map *doom)
{
	int	r;
	int	f;

	r = 0;
	f = 0;
	while (f < 640)
	{
		r = 0;
		while (r < 220)
		{
			mlx_put_pixel(doom->image1, f, r,
				ft_pixel(doom->data->c_value[0], doom->data->c_value[1],
					doom->data->c_value[2], 100));
			r++;
		}
		while (r < 440)
		{
			mlx_put_pixel(doom->image1, f, r,
				ft_pixel(doom->data->f_value[0], doom->data->f_value[1],
					doom->data->f_value[2], 255));
			r++;
		}
		f++;
	}
}

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

void	calc_first_hor(double ra, t_ray *hp, t_map *doom)
{
	if (ra >= M_PI)
	{
		hp->ry = (((int)(doom->cent_y / 40)) * 40) - 0.00001;
		hp->rx = doom->cent_x - ((doom->cent_y - hp->ry) / (tan(ra) + 0.00001));
		hp->yo = -40;
		hp->xo = hp->yo / (tan(ra) + 0.00001);
	}
	if (ra < M_PI)
	{
		hp->ry = (((int)(doom->cent_y / 40)) * 40) + 40;
		hp->rx = doom->cent_x + (doom->cent_y - hp->ry) / -(tan(ra) + 0.00001);
		hp->yo = 40;
		hp->xo = hp->yo / (tan(ra));
	}
}

void	hor_line(double *a, double *b, double *c, t_map *doom)
{
	t_ray	hp;
	double	ra;

	ra = *c;
	calc_first_hor(ra, &hp, doom);
	while (1)
	{
		if (((int)hp.rx > (doom->map_width)) || ((int)hp.ry
				> (doom->map_hight)) || ((int)hp.rx < 0)
			|| ((int)hp.ry < 0))
			break ;
		if (doom->data->map[(int)(hp.ry / 40)][(int)((hp.rx) / 40)] == '1')
			break ;
		if (hardcode(hp.ry, hp.rx, ra, doom) == 1)
			break ;
		else
		{
			hp.rx += hp.xo;
			hp.ry += hp.yo;
		}
	}
	*a = hp.ry;
	*b = hp.rx;
}
