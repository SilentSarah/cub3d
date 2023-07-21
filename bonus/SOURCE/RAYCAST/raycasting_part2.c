/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:20:08 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/21 15:28:05 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

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

void	ver_line(double *a, double *b, double *c, t_map *doom)
{
	t_ray	hp;
	double	ra;

	ra = *c;
	calc_first_ver(ra, &hp, doom);
	while (1)
	{
		if (((int)hp.rvx > (doom->map_width)) || ((int)hp.rvy
				> (doom->map_hight)) || ((int)hp.rvx < 0)
			|| ((int)hp.rvy < 0))
			break ;
		if (hardcode(hp.rvy, hp.rvx, ra, doom) == 1)
			break ;
		if (doom->data->map[(int)(hp.rvy / 40)][(int)(hp.rvx / 40)] == '1')
			break ;
		else
		{
			hp.rvx += hp.xo;
			hp.rvy += hp.yo;
		}
	}
	*a = hp.rvy;
	*b = hp.rvx;
}

void	where(t_rgba *rgb, double ra, int c, t_map *doom)
{
	if ((ra >= M_PI / 2) || ra < (3 * M_PI / 2))
	{
		rgb->red = doom->t->t[WE]->pixels[c];
		rgb->green = doom->t->t[WE]->pixels[c + 1];
		rgb->blue = doom->t->t[WE]->pixels[c + 2];
	}
	if ((ra < M_PI / 2) || ra >= (3 * M_PI / 2))
	{
		rgb->red = doom->t->t[EA]->pixels[c];
		rgb->green = doom->t->t[EA]->pixels[c + 1];
		rgb->blue = doom->t->t[EA]->pixels[c + 2];
	}
}

void	where1(t_rgba *rgb, double ra, int c, t_map *doom)
{
	if (ra > M_PI)
	{
		rgb->red = doom->t->t[NO]->pixels[c];
		rgb->green = doom->t->t[NO]->pixels[c + 1];
		rgb->blue = doom->t->t[NO]->pixels[c + 2];
	}
	else
	{
		rgb->red = doom->t->t[SO]->pixels[c];
		rgb->green = doom->t->t[SO]->pixels[c + 1];
		rgb->blue = doom->t->t[SO]->pixels[c + 2];
	}
}

void	project1_help(double ra, double ry, t_map *doom, t_project *hb)
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
