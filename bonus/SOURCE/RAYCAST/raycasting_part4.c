/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_part4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:32:38 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/21 15:33:21 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	drawline_help(t_bresnham_h *ll, t_bresnham pp)
{
	ll->dy = abs(pp.y1 - pp.y0);
	ll->dx = abs(pp.x1 - pp.x0);
	if (pp.x0 < pp.x1)
		ll->sx = 1;
	else
		ll->sx = -1;
	if (pp.y0 < pp.y1)
		ll->sy = 1;
	else
		ll->sy = -1;
	ll->err = ll->dx - ll->dy;
}

void	drawline1(t_bresnham pp, t_map *doom)
{
	t_bresnham_h	ll;

	drawline_help(&ll, pp);
	while (1)
	{
		mlx_put_pixel(doom->image1, pp.x0 * doom->map_s, pp.y0 * doom->map_s,
			ft_pixel(255, 0, 0, 255));
		if (pp.x0 == pp.x1 && pp.y0 == pp.y1)
			break ;
		ll.e2 = ll.err;
		if (ll.e2 > -ll.dy)
		{
			ll.err -= ll.dy;
			pp.x0 += ll.sx;
		}
		if (ll.e2 < ll.dx)
		{
			ll.err += ll.dx;
			pp.y0 += ll.sy;
		}
	}
}

void	drawline(t_bresnham pp, t_map *doom)
{
	t_bresnham_h	ll;

	drawline_help(&ll, pp);
	while (1)
	{
		mlx_put_pixel(doom->image1, pp.x0 * doom->map_s, pp.y0 * doom->map_s,
			ft_pixel(0, 0, 255, 255));
		if (pp.x0 == pp.x1 && pp.y0 == pp.y1)
			break ;
		ll.e2 = ll.err * 2;
		if (ll.e2 > -ll.dy)
		{
			ll.err -= ll.dy;
			pp.x0 += ll.sx;
		}
		if (ll.e2 < ll.dx)
		{
			ll.err += ll.dx;
			pp.y0 += ll.sy;
		}
	}
}

void	player(t_map *doom)
{
	int	f;
	int	r;
	int	y;
	int	x;

	f = doom->cent_x - 4;
	r = doom->cent_y - 4;
	x = doom->cent_x + 4;
	y = doom->cent_y + 4;
	while (f <= x)
	{
		r = doom->cent_y - 4;
		while (r <= y)
		{
			mlx_put_pixel(doom->image1, f * doom->map_s, r * doom->map_s,
				ft_pixel(255, 0, 0, 255));
			r++;
		}
		f++;
	}
}

void	draw_ray_map(t_map *doom)
{
	int			i;
	t_bresnham	pp;

	i = 0;
	pp.x0 = doom->cent_x;
	pp.y0 = doom->cent_y;
	while (i < 640)
	{
		pp.x1 = doom->rays[i][0];
		pp.y1 = doom->rays[i][1];
		drawline1(pp, doom);
		i++;
	}
	pp.x1 = doom->cent_x + doom->px;
	pp.y1 = doom->cent_y + doom->py;
	drawline(pp, doom);
}
