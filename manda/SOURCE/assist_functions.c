/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:33:17 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/20 18:10:26 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

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

void	calc_first_ver(double ra, t_ray *hp, t_map *doom)
{
	if ((ra >= M_PI / 2) || ra < (3 * M_PI / 2))
	{
		hp->rvx = (((int)(doom->cent_x / 40)) * 40) - 0.000001;
		hp->rvy = doom->cent_y - (doom->cent_x - hp->rvx) * tan(ra);
		hp->xo = -40;
		hp->yo = hp->xo * tan(ra);
	}
	if ((ra < M_PI / 2) || ra >= (3 * M_PI / 2))
	{
		hp->rvx = (((int)(doom->cent_x / 40)) * 40) + 40.0001;
		hp->rvy = doom->cent_y + (doom->cent_x - hp->rvx) * -tan(ra);
		hp->xo = 40;
		hp->yo = hp->xo * tan(ra);
	}
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

void	calculating(t_ray *r, t_map *doom)
{
	hor_line(&r->ry, &r->rx, &r->ra, doom);
	ver_line(&r->rvy, &r->rvx, &r->ra, doom);
	r->x1 = sqrt(pow((r->rx - doom->cent_x), 2) + pow((r->ry - doom->cent_y),
				2));
	r->x2 = sqrt(pow((r->rvx - doom->cent_x), 2) + pow((r->rvy - doom->cent_y),
				2));
}
