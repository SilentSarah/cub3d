/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:14:50 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/21 14:05:56 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	hor_line(double *a, double *b, double *c, t_map *doom)
{
	t_ray	hp;
	double	ra;

	ra = *c;
	calc_first_hor(ra, &hp, doom);
	while (1)
	{
		if (((int)hp.rx > (doom->map_width - 40)) || ((int)hp.ry
				> (doom->map_hight - 40)) || ((int)hp.rx < 0)
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

void	ver_line(double *a, double *b, double *c, t_map *doom)
{
	t_ray	hp;
	double	ra;

	ra = *c;
	calc_first_ver(ra, &hp, doom);
	while (1)
	{
		if (((int)hp.rvx > (doom->map_width - 40)) || ((int)hp.rvy
				> (doom->map_hight - 40)) || ((int)hp.rvx < 0)
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

void	ft_randering(void *parm)
{
	t_map	*doom;

	doom = (t_map *)parm;
	my_clear(doom);
	drawray(doom);
}
