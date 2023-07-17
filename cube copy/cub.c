/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:17:11 by hassimi           #+#    #+#             */
/*   Updated: 2023/07/17 20:04:42 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <MLX42/include/MLX42/MLX42.h>
#include <MLX42/include/MLX42/MLX42_Input.h>
#include <complex.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "pipi.ppm"
#include "texture.ppm"

#define WIDTH 512
// #define PI 3.14159265
	mlx_t* mlx;

float PI = M_PI , DR = M_PI / 180;
static mlx_image_t* image1;
static mlx_image_t* image2;
static mlx_image_t* image;
typedef struct s_texture{
	mlx_texture_t *north;
	mlx_texture_t *west;
	mlx_texture_t *south;
	mlx_texture_t *east;
}t_texture;
t_texture t;
double map_s = 0.2;
double rays[640][3];
char **map;
double dst = 0;
double cent_y = 190.005414, cent_x = 199.840863;
// double cent_y = 200, cent_x = 200;
double px,py,pa = M_PI_4;


// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void rect1(int x, int y)
{
	int r, f;
	r = 0;
	f = 0;

	while(++f <  40)
	{
		r = 0;
		while(++r < 40)
		{
			mlx_put_pixel(image1,  (r + (y * 40))*map_s, (f + (x * 40))*map_s , ft_pixel(255, 255, 255, 255));
		}
	}
}
void rect(int x, int y)
{
	int r, f;
	r = 0;
	f = 0;

	while(++f <  40)
	{
		r = 0;
		while(++r < 40)
		{
			mlx_put_pixel(image1,  (r + (y * 40))*map_s, (f + (x * 40))*map_s , ft_pixel(0, 0, 0, 255));
		}
	}
}

void rand_map(void)
{
	int x = 0,y = 0;
	while(map[x])
	{
		y = 0;
		while(map[x][y])
		{
			if (map[x][y] == '1')
				rect(x, y);
			else
			 	rect1(x, y);
			y++;
		}
		x++;
	}
}

// void player(void)
// {
// 	int x = -8;
// 	int y;
// 	int err;

// 	while (x <= 8)
// 	{
// 		y = -8;
// 		while (y <= 8)
// 		{
// 			err = x * x + y * y - 8 * 8;
// 			if (err <= 0)
// 				mlx_put_pixel(image1,  200 + y, 200 + x , ft_pixel(255, 0, 0, 255));
// 			y++;
// 		}
// 		x++;
// 	}
// 	double r= 0, t = 0;
// 	while(r < 40)
// 	{
// 		mlx_put_pixel(image1, 200 + t, 200 - r,  ft_pixel(255, 0, 0, 255));
// 		r++;
// 	}
// }

void drawline1(int x0, int y0, int x1, int y1)
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
		mlx_put_pixel(image1,  x0*map_s, y0*map_s, ft_pixel(255, 0, 0, 255));
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

void drawline(int x0, int y0, int x1, int y1)
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
		mlx_put_pixel(image1,  x0*map_s, y0*map_s, ft_pixel(0, 0, 255, 255));
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


void player(void)
{
int f = cent_x - 4;
int r = cent_y - 4;
int x = cent_x + 4;
int y = cent_y + 4;

while(f <= x)
{
	r = cent_y - 4;
	while(r <= y)
	{
		mlx_put_pixel(image1,	f*map_s, r*map_s, ft_pixel(255, 0, 0, 255));
		r++;
	}
	f++;
}
int i = 0;
while (i < 640)
{
	drawline1(cent_x, cent_y, rays[i][0], rays[i][1]);
	i++;
}
}
void my_clear()
{
	int r, f;
	r = 0;
	f = 0;

	while(f <  640)
	{
		r = 0;
		while(r < 220)
		{
			mlx_put_pixel(image1,  f, r, ft_pixel(0, 255, 255, 100));
			r++;
		}
		while(r < 440)
		{
			mlx_put_pixel(image1,  f, r, ft_pixel(255, 229, 204, 255));
			r++;
		}
		f++;
	}

}
int hardcode(int rvy,int rvx, double ra)
{
	if (ra <= 2 *PI && ra >= (PI + (PI /2))){
	if ((rvy > 0 && rvy < 560) && (rvx > 0 && rvy < 360))
	{
		if (map[rvy / 40 + 1][rvx / 40] == '1' && map[rvy / 40][rvx / 40 - 1] == '1')
			return (1);
	}}
	else if (ra <= (PI + (PI /2)) && ra > PI){
	if ((rvy > 0 && rvy < 560) && (rvx > 0 && rvy < 360))
	{
		if (map[rvy / 40][rvx / 40 + 1] == '1' && map[rvy / 40 + 1][rvx / 40] == '1')
			return (1);
	}
	}
	else if (ra <= PI && ra >= PI / 2){
	if ((rvy > 0 && rvy < 560) && (rvx > 0 && rvy < 360))
	{
			if (map[rvy / 40][rvx / 40 +1] == '1' && map[rvy / 40 -1][rvx / 40] == '1')
			return (1);

	}}
	else if(ra <= PI/2 && ra >= 0){
	if ((rvy > 0 && rvy < 560) && (rvx > 0 && rvy < 360))
	{
		if (map[rvy / 40][rvx / 40 -1] == '1' && map[rvy / 40-1][rvx / 40] == '1')
			return (1);
	}}
	return (0);
}

int hardcode1(int rvy,int rvx)
{
	if (pa <= 2 *PI && pa >= (PI + (PI /2))){
	if ((rvy > 0 && rvy < 560) && (rvx > 0 && rvy < 360))
	{
		if (map[(rvy + 20)/ 40][rvx / 40] == '1' && map[rvy / 40][(rvx - 20)/ 40] == '1')
			return (1);
	}}
	else if (pa <= (PI + (PI /2)) && pa > PI){
	if ((rvy > 0 && rvy < 560) && (rvx > 0 && rvy < 360))
	{
		if (map[rvy / 40][(rvx + 20) / 40] == '1' && map[(rvy + 20) / 40][rvx / 40] == '1')
			return (1);
	}
	}
	else if (pa <= PI && pa >= PI / 2){
	if ((rvy > 0 && rvy < 560) && (rvx > 0 && rvy < 360))
	{
			if (map[rvy / 40][(rvx + 20) / 40] == '1' && map[(rvy - 20) / 40][rvx / 40] == '1')
			return (1);

	}}
	else if(pa <= PI/2 && pa >= 0){
	if ((rvy > 0 && rvy < 560) && (rvx > 0 && rvy < 360))
	{
		if (map[rvy / 40][(rvx - 20) / 40] == '1' && map[(rvy - 20) / 40][rvx / 40] == '1')
			return (1);
	}}
	return (0);
}

void hor_line(double *a, double* b, double *c)
{
	double rx = 0, ry = 0;
	// int dof;
	double xo=0,yo =0 ;
	double ra = *c;
	if ( ra >= PI)
	{
		ry = (((int)(cent_y / 40))  *40)-0.00001;
		rx = cent_x - ((cent_y - ry) / (tan(ra)+0.00001));
		yo = -40;
		xo = yo / (tan(ra) + 0.00001);
	}
	if (ra < PI)
	{
		ry = (((int)(cent_y / 40))  *40) + 40;
		rx = cent_x + (cent_y - ry) / -(tan(ra)+0.00001);
		yo = 40;
		xo = yo / (tan(ra));
	}
	while(1)
	{
		if (((int)rx > 560) || ((int)ry > 360) || ((int)rx < 0) || ((int)ry < 0))
			break;
		if (map[(int)(ry / 40)][(int)((rx) / 40)] == '1')
				break;
		if (hardcode(ry, rx, ra) == 1)
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

void ver_line(double *a, double* b, double *c)
{
int mp=0,mx = 0, my = 0,dof;
	double xo=0,yo =0, rvx=0, rvy=0 ;
	double ra = *c;

		if ((ra >=  PI / 2) || ra < (3*PI/ 2))
		{
			rvx = (((int)(cent_x / 40)) * 40) - 0.000001;
			rvy = cent_y - (cent_x - rvx) * tan(ra);
			xo = -40;
			yo = xo * tan(ra);
		}
		if ((ra <  PI / 2) || ra >= (3*PI/ 2))
		{
			rvx = (((int)(cent_x / 40)) * 40) + 40.0001;
			rvy = cent_y + (cent_x - rvx) * -tan(ra);
			xo = +40;
			yo = xo * tan(ra);
		}
		while(1)
		{
		if (((int)rvx > 560) || ((int)rvy > 360) || ((int)rvx < 0) || ((int)rvy < 0))
			break;
		if (hardcode(rvy, rvx, ra) == 1)
				break;
			if (map[(int)(rvy / 40)][(int)(rvx / 40)] == '1')
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

void where(int *red, int *green, int*blue, double ra, int c)
{
		if ((ra >=  PI / 2) || ra < (3*PI/ 2))
		{
			*red = t.west->pixels[c+0];
			*green = t.west->pixels[c+1];
			*blue = t.west->pixels[c+2];
		}
		if ((ra <  PI / 2) || ra >= (3*PI/ 2))
		{
			*red = t.east->pixels[c+0];
			*green = t.east->pixels[c+1];
			*blue = t.east->pixels[c+2];
		}

}

void where1(int *red, int *green, int*blue, double ra, int c)
{
		if (ra >= M_PI && ra <= M_PI_2)
		{
			*red = t.north->pixels[c+0];
			*green = t.north->pixels[c+1];
			*blue = t.north->pixels[c+2];
		}
		else
		{
			*red = t.south->pixels[c+0];
			*green = t.south->pixels[c+1];
			*blue = t.south->pixels[c+2];
		}

}

void projecting1(int i, double ra, double rx)
{
	double ca = pa - ra;
	if (ca<0)
		ca += 2*M_PI;
	if ( ca > 2 * M_PI)
		ca -= 2 * M_PI;
	dst = dst * cos(ca);
	int lineh = (40*440)/dst;
	double ty_step = 64 / (double)lineh;
	double ty_off = 0;

	if (lineh > 440)
	{
		ty_off = (lineh-440)/2.0;
		lineh =440;
	}
	int lineo = (220 - lineh/2);
	int s = 0;
	int c,red, green, blue;
	double ty= ty_off * ty_step;

	double tx =(int)(rx / 0.625) % 64;
	if (ra > 180)
		tx = 63 -tx;
	while (s < lineh)
	{
		// c = lol[(int)ty*32 + (int)tx];
		// if (c == 1)
		// 	c = 255;
		c = ((int)ty*64 + (int)tx)*4;
		where1(&red, &green, &blue, ra, c);
		// red = t.north->pixels[(int)c + 0];
		// green = t.north->pixels[(int)c + 1];
		// blue = t.north->pixels[(int)c + 2];
		mlx_put_pixel(image1, i, s+lineo, ft_pixel(red, green, blue, 155));
		// mlx_put_pixel(image1, i, s+lineo, ft_pixel(c, c, c, 255));
		s++;
		ty += ty_step;
	}
}

void projecting2(int i, double ra, double ry)
{
	double ca = pa - ra;
	if (ca<0)
		ca += 2*M_PI;
	if ( ca > 2 * M_PI)
		ca -= 2 * M_PI;
	dst = dst * cos(ca);
	int lineh = (40*440)/dst;
	double ty_step = 64 / (double)lineh;
	double ty_off = 0;
	if (lineh > 440)
	{
		ty_off = (lineh-440)/2.0;
		lineh =440;
	}
	int lineo = (220 - lineh/2);
	int s = 0;
	int c,red, green, blue, opacity;
	double ty= ty_off*ty_step;
	double tx =(int)(ry / 0.625) % 64;
	if ( ra > 90 && ra < 270)
		tx = 63-tx;
	while (s < lineh)
	{
		// c = lol[(int)ty*32 + (int)tx];
		// if (c == 1)
		// 	c = 255;
		c = ((int)ty*64 + (int)tx)*4;
		where(&red, &green, &blue, ra, c);
		// red = t.south->pixels[(int)c + 0];
		// green = t.south->pixels[(int)c + 1];
		// blue = t.south->pixels[(int)c + 2];
		mlx_put_pixel(image1, i, s+lineo, ft_pixel(red, green, blue, 255));
		s++;
		ty += ty_step;
	}
}

void drawray()
{
	double rx=10000000,ry=100000,rvx=10000000,rvy =10000000; int i = 0 ;
	double ra;
	ra = pa - DR *30;
	// ra = pa;
	if(ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	while ( i < 640)
	{
	hor_line(&ry, &rx, &ra);
	ver_line(&rvy, &rvx, &ra);
	double x1 = 0;
	double x2 = 0;
	x1 = sqrt(pow((rx - cent_x), 2) + pow((ry - cent_y), 2));
	x2 = sqrt(pow((rvx - cent_x), 2) + pow((rvy - cent_y), 2));
	if (x2 > x1)
	{
		dst = x1;
		projecting1(i, ra, rx);
		rays[i][0] = rx;
		rays[i][1] = ry;
		// drawline1(cent_x, cent_y, rx, ry);
	}
	else if (x2 < x1)
	{
		dst = x2;
		projecting2(i, ra, rvy);
		rays[i][0] = rvx;
		rays[i][1] = rvy;
		// drawline1(cent_x, cent_y, rvx, rvy);
	}
	i++;
	 ra += (DR*60)/640;
		if(ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
	}
}
void ft_randomize(void *parm)
{
	my_clear();
	drawray();
	drawline(cent_x, cent_y, (cent_x + px), (cent_y + py));
	rand_map();
	player();
}

void ft_hook(mlx_key_data_t keydata, void* param)
{
	double xtemp = 0, ytemp = 0;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit(0);
	if (keydata.key == MLX_KEY_UP)
	{
		xtemp =cent_x + cos(pa)*5;
		ytemp = cent_y + sin(pa)*5;
		if (map[(int)(ytemp /40)][(int)xtemp / 40] != '1' )
		{
			if((int)xtemp / 40!=(int)cent_x / 40 && (int)ytemp / 40!=(int)cent_y / 40 && map[(int)ytemp /40][(int)cent_x / 40] == '1'&& map[(int)cent_y /40][(int)xtemp / 40] == '1' )
				return;
			cent_x =xtemp;
			cent_y =ytemp;
		}

	}
	if (keydata.key == MLX_KEY_DOWN)
	{
		xtemp =cent_x - cos(pa)*5;
		ytemp = cent_y - sin(pa)*5;
		if (map[(int)ytemp /40][(int)xtemp / 40] != '1')
		{
			if((int)xtemp / 40!=(int)cent_x / 40 && (int)ytemp / 40!=(int)cent_y / 40 && map[(int)ytemp /40][(int)cent_x / 40] == '1'&& map[(int)cent_y /40][(int)xtemp / 40] == '1' )
					return;
				cent_x =xtemp;
				cent_y =ytemp;
		}
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		ytemp =cent_y + cos(-pa)*5;
		xtemp =cent_x + sin(-pa)*5;
		if (map[(int)ytemp /40][(int)xtemp / 40] != '1')
		{
			if((int)xtemp / 40!=(int)cent_x / 40 && (int)ytemp / 40!=(int)cent_y / 40 && map[(int)ytemp /40][(int)cent_x / 40] == '1'&& map[(int)cent_y /40][(int)xtemp / 40] == '1' )
				return;
			cent_x =xtemp;
			cent_y =ytemp;
		}
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		ytemp = cent_y - cos(-pa)*5;
		xtemp = cent_x - sin(-pa)*5;
		if (map[(int)ytemp /40][(int)xtemp / 40] != '1')
		{
			if((int)xtemp / 40!=(int)cent_x / 40 && (int)ytemp / 40!=(int)cent_y / 40 && map[(int)ytemp /40][(int)cent_x / 40] == '1'&& map[(int)cent_y /40][(int)xtemp / 40] == '1' )
				return;
			cent_x = xtemp;
			cent_y = ytemp;

		}
	}
	if (keydata.key == MLX_KEY_A)
	{
		pa -= 0.05;
		if (pa <= 0)
			pa+=2*PI;
		px = cos(pa) * 50;
		py = sin(pa) * 50 ;
	}
	if (keydata.key == MLX_KEY_D)
	{
		pa += 0.05;
		if (pa >= 2 * PI)
			pa-=2*PI;
		px = cos(pa) * 50;
		py = sin(pa) * 50;
	}
}

// -----------------------------------------------------------------------------

int32_t main(int32_t argc, const char* argv[])
{
	map = malloc(sizeof(char) * 10 + 1);
	map[0] = "111111111111111";
	map[1] = "100000001010001";
	map[2] = "100000001010001";
	map[3] = "100000001010001";
	map[4] = "100000010100001";
	map[5] = "100100000000001";
	map[6] = "100100010000011";
	map[7] = "100000001000101";
	map[8] = "100000000000001";
	map[9] = "111111111111111";
	map[10] = 0;
	pa = 5.530000;
	px = cos(pa) * 40;
	py = sin(pa) * 40;
	// Gotta error check this stuff
	if (!(mlx = mlx_init(600, 400, "MLX42", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	t.north = mlx_load_png("./north.png");
	t.south = mlx_load_png("./south.png");
	t.west = mlx_load_png("./west.png");
	t.east = mlx_load_png("./east.png");
	image = mlx_new_image(mlx, 640, 440);
	image2 = mlx_new_image(mlx, 640, 440);
	image1 = mlx_new_image(mlx, 640, 440);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_image_to_window(mlx, image1, 0, 0);
	// mlx_image_to_window(mlx, image2, 0, 0);
	mlx_key_hook(mlx,&ft_hook, 0);
	mlx_loop_hook(mlx, ft_randomize, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}