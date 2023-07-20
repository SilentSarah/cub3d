/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:17:11 by hassimi           #+#    #+#             */
/*   Updated: 2023/07/20 15:33:41 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"



// -----------------------------------------------------------------------------

int ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void rect1(int x, int y, t_map *doom)
{
	int r, f;
	r = 0;
	f = 0;

	while(++f <  40)
	{
		r = 0;
		while(++r < 40)
		{
			mlx_put_pixel(doom->image1,  (r + (y * 40))*doom->map_s, (f + (x * 40))*doom->map_s , ft_pixel(255, 255, 255, 255));
		}
	}
}
void rect(int x, int y, t_map *doom)
{
	int r, f;
	r = 0;
	f = 0;

	while(++f <  40)
	{
		r = 0;
		while(++r < 40)
		{
			mlx_put_pixel(doom->image1,  (r + (y * 40))* doom->map_s, (f + (x * 40))*doom->map_s , ft_pixel(0, 0, 0, 255));
		}
	}
}

void rand_map(t_map *doom)
{
	int x = 0,y = 0;
	while(doom->data->map[x])
	{
		y = 0;
		while(doom->data->map[x][y])
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

void drawline1(int x0, int y0, int x1, int y1, t_map *doom)
{
	int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy;
    if (x0 < x1)
        sx = 1;
    else
        sx = -1;
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;

    int err = dx - dy;
    int e2;
    while (1)
    {
		mlx_put_pixel(doom->image1,  x0*doom->map_s, y0*doom->map_s, ft_pixel(255, 0, 0, 255));
		// mlx_put_pixel(image1,  x0, y0, 0xFF0000FF);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void drawline(int x0, int y0, int x1, int y1, t_map *doom)
{
	int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy;
    if (x0 < x1)
        sx = 1;
    else
        sx = -1;
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;

    int err = dx - dy;
    int e2;
    while (1)
    {
		mlx_put_pixel(doom->image1,  x0*doom->map_s, y0*doom->map_s, ft_pixel(0, 0, 255, 255));
        if (x0 == x1 && y0 == y1)
            break;
        e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}


void player(t_map *doom)
{
int f = doom->cent_x - 4;
int r = doom->cent_y - 4;
int x = doom->cent_x + 4;
int y = doom->cent_y + 4;

while(f <= x)
{
	r = doom->cent_y - 4;
	while(r <= y)
	{
		mlx_put_pixel(doom->image1,	f*doom->map_s, r*doom->map_s, ft_pixel(255, 0, 0, 255));
		r++;
	}
	f++;
}
int i = 0;
while (i < 640)
{
	drawline1(doom->cent_x,doom-> cent_y, doom->rays[i][0], doom->rays[i][1], doom);
	i++;
}
}
void my_clear(t_map *doom)
{
	int r, f;
	r = 0;
	f = 0;
	while(f <  640)
	{
		r = 0;
		while(r < 220)
		{
			mlx_put_pixel(doom->image1,  f, r, ft_pixel(doom->data->c_value[0], doom->data->c_value[1], doom->data->c_value[2], 100));
			r++;
		}
		while(r < 440)
		{
			mlx_put_pixel(doom->image1,  f, r, ft_pixel(doom->data->f_value[0], doom->data->f_value[1], doom->data->f_value[2], 255));
			r++;
		}
		f++;
	}

}
int hardcode(int rvy,int rvx, double ra, t_map *doom)
{
	if (ra <= 2 *M_PI && ra >= (M_PI + (M_PI /2))){
	if ((rvy > 0 && rvy < (doom->map_width - 80)) && (rvx > 0 && rvy < (doom->map_hight-80)))
	{
		if (doom->data->map[rvy / 40 + 1][rvx / 40] == '1' && doom->data->map[rvy / 40][rvx / 40 - 1] == '1')
			return (1);
	}}
	else if (ra <= (M_PI + (M_PI /2)) && ra > M_PI){
	if ((rvy > 0 && rvy < (doom->map_width - 80)) && (rvx > 0 && rvy < (doom->map_hight-80)))
	{
		if (doom->data->map[rvy / 40][rvx / 40 + 1] == '1' && doom->data->map[rvy / 40 + 1][rvx / 40] == '1')
			return (1);
	}
	}
	else if (ra <= M_PI && ra >= M_PI / 2){
	if ((rvy > 0 && rvy < (doom->map_width - 80)) && (rvx > 0 && rvy < (doom->map_hight-80)))
	{
			if (doom->data->map[rvy / 40][rvx / 40 +1] == '1' && doom->data->map[rvy / 40 -1][rvx / 40] == '1')
			return (1);

	}}
	else if(ra <= M_PI/2 && ra >= 0){
	if ((rvy > 0 && rvy < (doom->map_width - 80)) && (rvx > 0 && rvy < (doom->map_hight-80)))
	{
		if (doom->data->map[rvy / 40][rvx / 40 -1] == '1' && doom->data->map[rvy / 40-1][rvx / 40] == '1')
			return (1);
	}}
	return (0);
}

void hor_line(double *a, double* b, double *c, t_map *doom)
{
	double rx = 0, ry = 0;
	// int dof;
	double xo=0,yo =0 ;
	double ra = *c;
	if ( ra >= M_PI)
	{
		ry = (((int)(doom->cent_y / 40))  *40)-0.00001;
		rx = doom->cent_x - ((doom->cent_y - ry) / (tan(ra)+0.00001));
		yo = -40;
		xo = yo / (tan(ra) + 0.00001);
	}
	if (ra < M_PI)
	{
		ry = (((int)(doom->cent_y / 40))  *40) + 40;
		rx = doom->cent_x + (doom->cent_y - ry) / -(tan(ra)+0.00001);
		yo = 40;
		xo = yo / (tan(ra));
	}
	while(1)
	{
		if (((int)rx > (doom->map_width-80)) || ((int)ry > (doom->map_hight-40)) || ((int)rx < 0) || ((int)ry < 0))
			break;
		if (doom->data->map[(int)(ry / 40)][(int)((rx) / 40)] == '1')
				break;
		if (hardcode(ry, rx, ra, doom) == 1)
				break;
		else
		{
			rx +=xo;
			ry+=yo;
		}
	}
		*a = ry;
		*b = rx;
}

void ver_line(double *a, double* b, double *c, t_map *doom)
{
int mp=0,mx = 0, my = 0,dof;
	double xo=0,yo =0, rvx=0, rvy=0 ;
	double ra = *c;

		if ((ra >=  M_PI / 2) || ra < (3*M_PI/ 2))
		{
			rvx = (((int)(doom->cent_x / 40)) * 40) - 0.000001;
			rvy = doom->cent_y - (doom->cent_x - rvx) * tan(ra);
			xo = -40;
			yo = xo * tan(ra);
		}
		if ((ra <  M_PI / 2) || ra >= (3*M_PI/ 2))
		{
			rvx = (((int)(doom->cent_x / 40)) * 40) + 40.0001;
			rvy = doom->cent_y + (doom->cent_x - rvx) * -tan(ra);
			xo = +40;
			yo = xo * tan(ra);
		}
		while(1)
		{
		if (((int)rvx > (doom->map_width-80)) || ((int)rvy > (doom->map_hight-40)) || ((int)rvx < 0) || ((int)rvy < 0))
			break;
		// if (hardcode(rvy, rvx, ra, doom) == 1)
		// 		break;
			if (doom->data->map[(int)(rvy / 40)][(int)(rvx / 40)] == '1')
					break;
			else
			{
				rvx +=xo;
				rvy+=yo;
			}
		}
		*a = rvy;
		*b = rvx;
}

void where(int *red, int *green, int*blue, double ra, int c, t_map *doom)
{
		if ((ra >=  M_PI / 2) || ra < (3*M_PI/ 2))
		{
			*red = doom->t->t[WE]->pixels[c+0];
			*green = doom->t->t[WE]->pixels[c+1];
			*blue = doom->t->t[WE]->pixels[c+2];
		}
		if ((ra <  M_PI / 2) || ra >= (3*M_PI/ 2))
		{
			*red = doom->t->t[EA]->pixels[c+0];
			*green = doom->t->t[EA]->pixels[c+1];
			*blue = doom->t->t[EA]->pixels[c+2];
		}

}

void where1(int *red, int *green, int*blue, double ra, int c, t_map *doom)
{
		if (ra > M_PI)
		{
			*red = doom->t->t[NO]->pixels[c];
			*green = doom->t->t[NO]->pixels[c+1];
			*blue = doom->t->t[NO]->pixels[c+2];
			// *red = 255;
			// *green = 0;
			// *blue = 0;
		}
		else
		{
			*red = doom->t->t[SO]->pixels[c+0];
			*green = doom->t->t[SO]->pixels[c+1];
			*blue = doom->t->t[SO]->pixels[c+2];
			// *red = 255;
			// *green = 0;
			// *blue = 0;
		}
}

void projecting1(int i, double ra, double rx, t_map *doom)
{
	double ca = doom->pa - ra;
	if (ca<0)
		ca += 2*M_PI;
	if ( ca > 2 * M_PI)
		ca -= 2 * M_PI;
	doom->dst = doom->dst * cos(ca);
	int lineh = (40*440)/doom->dst;
	double ty_step = 64 / (double)lineh;
	double ty_off = 0;

	if (lineh > 440)
	{
		ty_off = (lineh-440)/2.0;
		lineh =440;
	}
	int lineo = ((220) - (lineh/2));
	int s = 0;
	int c,red, green, blue;
	double ty= ty_off * ty_step;

	double tx =(int)(rx / 0.625) % 64;
	if (ra > 180)
		tx = 63 -tx;
	while (s < lineh)
	{
		c = ((int)ty*64 + (int)tx)*4;
		where1(&red, &green, &blue, ra, c, doom);
		mlx_put_pixel(doom->image1, i, s+lineo, ft_pixel(red, green, blue, 155));
		s++;
		ty += ty_step;
	}
}

void projecting2(int i, double ra, double ry, t_map *doom)
{
	double ca = doom->pa - ra;
	if (ca<0)
		ca += 2*M_PI;
	if ( ca > 2 * M_PI)
		ca -= 2 * M_PI;
	doom->dst = doom->dst * cos(ca);
	int lineh = (40*440)/doom->dst;
	double ty_step = 64 / (double)lineh;
	double ty_off = 0;
	if (lineh > 440)
	{
		ty_off = (lineh-440)/2.0;
		lineh =440;
	}
	int lineo = ((220) - (lineh/2));
	int s = 0;
	int c,red, green, blue, opacity;
	double ty= ty_off*ty_step;
	double tx =(int)(ry / 0.625) % 64;
	if ( ra > 90 && ra < 270)
		tx = 63-tx;
	while (s < lineh)
	{
		c = ((int)ty*64 + (int)tx)*4;
		where(&red, &green, &blue, ra, c, doom);
		mlx_put_pixel(doom->image1, i, s+lineo, ft_pixel(red, green, blue, 255));
		s++;
		ty += ty_step;
	}
}

void drawray(t_map *doom)
{
	double rx=10000,ry=1000,rvx=10000,rvy =10000; int i = 0 ;
	double ra;
	ra = doom->pa - doom->dr *30;
	if(ra < 0)
		ra += 2 * M_PI;
	if (ra > 2 * M_PI)
		ra -= 2 * M_PI;
	while ( i < 640)
	{
	hor_line(&ry, &rx, &ra, doom);
	ver_line(&rvy, &rvx, &ra, doom);
	double x1 = 0;
	double x2 = 0;
	x1 = sqrt(pow((rx - doom->cent_x), 2) + pow((ry - doom->cent_y), 2));
	x2 = sqrt(pow((rvx - doom->cent_x), 2) + pow((rvy - doom->cent_y), 2));
	if (x2 > x1)
	{
		doom->dst = x1;
		projecting1(i, ra, rx, doom);
		doom->rays[i][0] = rx;
		doom->rays[i][1] = ry;
	}
	else if (x2 < x1)
	{
		doom->dst = x2;
		projecting2(i, ra, rvy, doom);
		doom->rays[i][0] = rvx;
		doom->rays[i][1] = rvy;
	}
	i++;
	 ra += (doom->dr*60)/640;
		if(ra < 0)
			ra += 2 * M_PI;
		if (ra > 2 * M_PI)
			ra -= 2 * M_PI;
	}
}
void ft_randomize(void *parm)
{
	t_map *doom;

	doom = (t_map *)parm;
	my_clear(doom);
	drawray(doom);
	rand_map(doom);
	player(doom);
	drawline(doom->cent_x, doom->cent_y, (doom->cent_x + doom->px), (doom->cent_y + doom->py), doom);
}

void ft_hook(mlx_key_data_t keydata, void* param)
{
	t_map *doom;

	doom = (t_map *)param;
	double xtemp = 0, ytemp = 0;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit(0);
	if (keydata.key == MLX_KEY_UP)
	{
		xtemp =doom->cent_x + cos(doom->pa)*5;
		ytemp = doom->cent_y + sin(doom->pa)*5;
		if (doom->data->map[(int)(ytemp /40)][(int)xtemp / 40] != '1' )
		{
			if((int)xtemp / 40!=(int)doom->cent_x / 40 && (int)ytemp / 40!=(int)doom->cent_y / 40 && doom->data->map[(int)ytemp /40][(int)doom->cent_x / 40] == '1'&& doom->data->map[(int)doom->cent_y /40][(int)xtemp / 40] == '1' )
				return;
			doom->cent_x =xtemp;
			doom->cent_y =ytemp;
		}

	}
	if (keydata.key == MLX_KEY_DOWN)
	{
		xtemp =doom->cent_x - cos(doom->pa)*5;
		ytemp = doom->cent_y - sin(doom->pa)*5;
		if (doom->data->map[(int)ytemp /40][(int)xtemp / 40] != '1')
		{
			if((int)xtemp / 40!=(int)doom->cent_x / 40 && (int)ytemp / 40!=(int)doom->cent_y / 40 && doom->data->map[(int)ytemp /40][(int)doom->cent_x / 40] == '1'&& doom->data->map[(int)doom->cent_y /40][(int)xtemp / 40] == '1')
					return;
				doom->cent_x =xtemp;
				doom->cent_y =ytemp;
		}
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		ytemp =doom->cent_y + cos(-doom->pa)*5;
		xtemp =doom->cent_x + sin(-doom->pa)*5;
		if (doom->data->map[(int)ytemp /40][(int)xtemp / 40] != '1')
		{
			if((int)xtemp / 40!=(int)doom->cent_x / 40 && (int)ytemp / 40!=(int)doom->cent_y / 40 &&doom->data->map[(int)ytemp /40][(int)doom->cent_x / 40] == '1'&& doom->data->map[(int)doom->cent_y /40][(int)xtemp / 40] == '1')
				return;
			doom->cent_x =xtemp;
			doom->cent_y =ytemp;
		}
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		ytemp = doom->cent_y - cos(-doom->pa)*5;
		xtemp = doom->cent_x - sin(-doom->pa)*5;
		if (doom->data->map[(int)ytemp /40][(int)xtemp / 40] != '1')
		{
			if((int)xtemp / 40!=(int)doom->cent_x / 40 && (int)ytemp / 40!=(int)doom->cent_y / 40 && doom->data->map[(int)ytemp /40][(int)doom->cent_x / 40] == '1'&& doom->data->map[(int)doom->cent_y /40][(int)xtemp / 40] == '1' )
				return;
			doom->cent_x = xtemp;
			doom->cent_y = ytemp;

		}
	}
	if (keydata.key == MLX_KEY_A)
	{
		doom->pa -= 0.05;
		if (doom->pa <= 0)
			doom->pa+=2*M_PI;
		doom->px = cos(doom->pa) * 40;
		doom->py = sin(doom->pa) * 40;
	}
	if (keydata.key == MLX_KEY_D)
	{
	doom->pa += 0.05;
		if (doom->pa >= 2 * M_PI)
			doom->pa-=2*M_PI;
		doom->px = cos(doom->pa) * 40;
		doom->py = sin(doom->pa) * 40;
	}
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
	if (doom->map_width < 640)
		doom->map_width = 640;
	printf("%d  %d\n",doom->doom_width, doom->doom_hight);
	printf("%d  %d\n",doom->map_width, doom->map_hight);
	doom->map_s = 0.2;
	doom->dr = M_PI / 180;
	doom->pa = M_PI;
	// if (doom->data->map[(int)doom->pinfo->pos_y][(int)doom->pinfo->pos_x] ==
	// 	'N')
	// 	doom->pa = M_PI + M_PI_2;
	// if (doom->data->map[(int)doom->pinfo->pos_y][(int)doom->pinfo->pos_x] ==
	// 	'S')
	// 	doom->pa = M_PI_2;
	// if (doom->data->map[(int)doom->pinfo->pos_y][(int)doom->pinfo->pos_x] ==
	// 	'W')
	// 	doom->pa = M_PI;
	// if (doom->data->map[(int)doom->pinfo->pos_y][(int)doom->pinfo->pos_x] ==
	// 	'E')
	// 	doom->pa = 2 * M_PI;
	doom->px = cos(doom->pa) * 40;
	doom->py = sin(doom->pa) * 40;
}

int raycasting(t_map *doom)
{
	assigning(doom);
	doom->image1 = mlx_new_image(doom->mlx, doom->map_width, doom->map_hight);
	if (!doom->image1)
		exit(1);
	mlx_image_to_window(doom->mlx, doom->image1, 0, 0);
	mlx_key_hook(doom->mlx,&ft_hook, doom);
	mlx_loop_hook(doom->mlx, &ft_randomize, doom);
	mlx_loop(doom->mlx);
	mlx_terminate(doom->mlx);
	return (EXIT_SUCCESS);
}