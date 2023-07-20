/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:17:11 by hassimi           #+#    #+#             */
/*   Updated: 2023/07/20 16:43:37 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"
#include <math.h>
#include "stdio.h"

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
			mlx_put_pixel(doom->image1,  (r + (y * 40))*doom->map_s, (f + (x * 40))*doom->map_s , ft_pixel(255, 255, 255, 255));
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
			mlx_put_pixel(doom->image1,  (r + (y * 40))*doom->map_s, (f + (x * 40))*doom->map_s , ft_pixel(0, 0, 0, 255));
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
void drawline_help(t_bresnham_h *ll, t_bresnham pp)
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

void drawline(t_bresnham pp, t_map *doom)
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
		if (((int)hp.rx > (doom->map_width - 80)) || ((int)hp.ry
				> (doom->map_hight - 80)) || ((int)hp.rx < 0)
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

void ver_line(double *a, double *b, double *c, t_map *doom)
{
	t_ray	hp;
	double	ra;

	ra = *c;
	calc_first_ver(ra, &hp, doom);
	while (1)
	{
		if (((int)hp.rvx > (doom->map_width - 80)) || ((int)hp.rvy
				> (doom->map_hight - 80)) || ((int)hp.rvx < 0)
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

void where(t_rgba *rgb, double ra, int c,t_map *doom)
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

void where1(t_rgba *rgb, double ra, int c, t_map *doom)
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
void project1_help(double ra, double ry, t_map *doom, t_project *hb)
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
void projecting1(int i, double ra, double ry, t_map *doom)
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

void project2_help(double ra, double ry, t_map *doom, t_project *hb)
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

void projecting2(int i, double ra, double ry, t_map *doom)
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

void calculating(t_ray *r, t_map *doom)
{
	hor_line(&r->ry, &r->rx, &r->ra, doom);
	ver_line(&r->rvy, &r->rvx, &r->ra, doom);
	r->x1 = sqrt(pow((r->rx - doom->cent_x), 2) + pow((r->ry - doom->cent_y),
				2));
	r->x2 = sqrt(pow((r->rvx - doom->cent_x), 2) + pow((r->rvy - doom->cent_y),
				2));
}

void project(t_ray	*r, t_map *doom, int i)
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
void drawray(t_map *doom)
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
void ft_randering(void *parm)
{
	t_map	*doom;

	doom = (t_map *)parm;
	my_clear(doom);
	drawray(doom);
	rand_map(doom);
	player(doom);
	draw_ray_map(doom);
}

void	key_w(t_map *doom)
{
	double	xtemp;
	double	ytemp;

	xtemp = 0;
	ytemp = 0;
	xtemp = doom->cent_x + cos(doom->pa) * 5;
	ytemp = doom->cent_y + sin(doom->pa) * 5;
	if (doom->data->map[(int)(ytemp / 40)][(int)xtemp / 40] != '1')
	{
		if ((int)xtemp / 40 != (int)doom->cent_x / 40
			&& (int)ytemp / 40 != (int)doom->cent_y / 40
			&& doom->data->map[(int)ytemp / 40][(int)doom->cent_x / 40] == '1'
			&& doom->data->map[(int)doom->cent_y / 40][(int)xtemp / 40] == '1' )
			return ;
		doom->cent_x = xtemp;
		doom->cent_y = ytemp;
	}
}

void	key_down(t_map *doom)
{
	double	xtemp;
	double	ytemp;

	xtemp = 0;
	ytemp = 0;
	xtemp = doom->cent_x - cos(doom->pa) * 5;
	ytemp = doom->cent_y - sin(doom->pa) * 5;
	if (doom->data->map[(int)ytemp / 40][(int)xtemp / 40] != '1')
	{
		if ((int)xtemp / 40 != (int)doom->cent_x / 40 && (int)ytemp / 40
			!= (int)doom->cent_y / 40 && doom->data->map[(int)ytemp / 40][(int)
			doom->cent_x / 40] == '1' && doom->data->map[(int)doom->cent_y /
			40][(int)xtemp / 40] == '1')
			return ;
		doom->cent_x = xtemp;
		doom->cent_y = ytemp;
	}
}

void	key_right(t_map *doom)
{
	double	xtemp;
	double	ytemp;

	xtemp = 0;
	ytemp = 0;
	ytemp = doom->cent_y + cos(-doom->pa) * 5;
	xtemp = doom->cent_x + sin(-doom->pa) * 5;
	if (doom->data->map[(int)ytemp / 40][(int)xtemp / 40] != '1')
	{
		if ((int)xtemp / 40 != (int)doom->cent_x / 40 && (int)ytemp / 40
			!= (int)doom->cent_y / 40 && doom->data->map[(int)ytemp / 40][(int)
			doom->cent_x / 40] == '1' && doom->data->map[(int)doom->cent_y /
			40][(int)xtemp / 40] == '1')
			return ;
		doom->cent_x = xtemp;
		doom->cent_y = ytemp;
	}
}

void	key_left(t_map *doom)
{
	double	xtemp;
	double	ytemp;

	xtemp = 0;
	ytemp = 0;
	ytemp = doom->cent_y - cos(-doom->pa) * 5;
	xtemp = doom->cent_x - sin(-doom->pa) * 5;
	if (doom->data->map[(int)ytemp / 40][(int)xtemp / 40] != '1')
	{
		if ((int)xtemp / 40 != (int)doom->cent_x / 40 && (int)ytemp / 40
			!= (int)doom->cent_y / 40 && doom->data->map[(int)ytemp / 40][(int)
			doom->cent_x / 40] == '1' && doom->data->map[(int)doom->cent_y /
			40][(int)xtemp / 40] == '1')
			return ;
		doom->cent_x = xtemp;
		doom->cent_y = ytemp;
	}
}

void	turn_right(t_map *doom)
{
	doom->pa -= 0.05;
	if (doom->pa <= 0)
		doom->pa += 2 * M_PI;
	doom->px = cos(doom->pa) * 40;
	doom->py = sin(doom->pa) * 40;
}
void	turn_left(t_map *doom)
{
	doom->pa += 0.05;
	if (doom->pa >= 2 * M_PI)
		doom->pa -= 2 * M_PI;
	doom->px = cos(doom->pa) * 40;
	doom->py = sin(doom->pa) * 40;
}
void ft_hook(mlx_key_data_t keydata, void* param)
{
	t_map	*doom;

	doom = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit(0);
	if (keydata.key == MLX_KEY_W)
		key_w(doom);
	if (keydata.key == MLX_KEY_S)
		key_down(doom);
	if (keydata.key == MLX_KEY_D)
		key_right(doom);
	if (keydata.key == MLX_KEY_A)
		key_left(doom);
	if (keydata.key == MLX_KEY_RIGHT)
		turn_right(doom);
	if (keydata.key == MLX_KEY_LEFT)
		turn_left(doom);
}

void mous_hook(double xdelta, double ydelta, void* param)
{
	t_map	*doom;

	doom = (t_map *)param;
	if (xdelta < 100)
		turn_left(doom);
	if (xdelta > 100)
		turn_right(doom);
	if (xdelta != 100)
		mlx_set_mouse_pos(doom->mlx, 100, 100);
	if (ydelta != 100)
		mlx_set_mouse_pos(doom->mlx, 100, 100);
}
// -----------------------------------------------------------------------------
void	assigning(t_map *doom)
{
	doom->cent_x = (doom->pinfo->pos_x * 40) + 40;
	doom->cent_y = (doom->pinfo->pos_y * 40) + 40;
	doom->map_hight = (40 * doom->doom_hight) + 40;
	if (doom->map_hight < 440)
		doom->map_hight = 440;
	doom->map_width = (40 * doom->doom_width) + 40;
	if (doom->map_width < 440)
		doom->map_width = 440;
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

int raycasting(t_map *doom)
{
	assigning(doom);
	doom->image1 = mlx_new_image(doom->mlx, doom->map_width,
			doom->map_hight);
	mlx_set_cursor_mode(doom->mlx, MLX_MOUSE_HIDDEN);
	mlx_image_to_window(doom->mlx, doom->image1, 0, 0);
	mlx_cursor_hook(doom->mlx, mous_hook, doom);
	mlx_key_hook(doom->mlx, &ft_hook, doom);
	mlx_loop_hook(doom->mlx, ft_randering, doom);
	mlx_loop(doom->mlx);
	mlx_terminate(doom->mlx);
	return (EXIT_SUCCESS);
}
