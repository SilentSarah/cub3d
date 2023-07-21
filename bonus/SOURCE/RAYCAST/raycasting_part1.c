/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:19:47 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/21 15:27:16 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	projecting1(int i, double ra, double ry, t_map *doom)
{
	t_project	hb;
	t_rgba		rgb;
	int			c;
	int			s;

	s = 0;
	project1_help(ra, ry, doom, &hb);
	while (s < hb.lineh)
	{
		c = ((int)hb.ty * 64 + (int)hb.tx) * 4;
		where1(&rgb, ra, c, doom);
		mlx_put_pixel(doom->image1, i, s + hb.lineo,
			ft_pixel(rgb.red, rgb.green, rgb.blue, 155));
		s++;
		hb.ty += hb.ty_step;
	}
}

void	project2_help(double ra, double ry, t_map *doom, t_project *hb)
{
	hb->ca = doom->pa - ra;
	if (hb->ca < 0)
		hb->ca += 2 * M_PI;
	if (hb->ca > 2 * M_PI)
		hb->ca -= 2 * M_PI;
	doom->dst = doom->dst * cos(hb->ca);
	hb->lineh = (40 * 440) / doom->dst;
	hb->ty_step = 64 / (double)hb->lineh;
	hb->ty_off = 0;
	if (hb->lineh > 440)
	{
		hb->ty_off = (hb->lineh - 440) / 2.0;
		hb->lineh = 440;
	}
	hb->lineo = ((220) - (hb->lineh / 2));
	hb->ty = hb->ty_off * hb->ty_step;
	hb->tx = (int)(ry / 0.625) % 64;
	if (ra > 90 && ra < 270)
		hb->tx = 63 - hb->tx;
}

void	projecting2(int i, double ra, double ry, t_map *doom)
{
	t_project	hb;
	t_rgba		rgb;
	int			c;
	int			s;

	s = 0;
	project2_help(ra, ry, doom, &hb);
	while (s < hb.lineh)
	{
		c = ((int)hb.ty * 64 + (int)hb.tx) * 4;
		where(&rgb, ra, c, doom);
		mlx_put_pixel(doom->image1, i, s + hb.lineo,
			ft_pixel(rgb.red, rgb.green, rgb.blue, 255));
		s++;
		hb.ty += hb.ty_step;
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

void	project(t_ray	*r, t_map *doom, int i)
{
	if (r->x2 > r->x1)
	{
		doom->dst = r->x1;
		projecting1(i, r->ra, r->rx, doom);
		doom->rays[i][0] = r->rx;
		doom->rays[i][1] = r->ry;
	}
	else if (r->x2 < r->x1)
	{
		doom->dst = r->x2;
		projecting2(i, r->ra, r->rvy, doom);
		doom->rays[i][0] = r->rvx;
		doom->rays[i][1] = r->rvy;
	}
}
