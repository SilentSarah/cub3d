/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:17:11 by hassimi           #+#    #+#             */
/*   Updated: 2023/07/15 15:00:56 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <MLX42/include/MLX42/MLX42.h>
#include <MLX42/include/MLX42/MLX42_Input.h>
#include <complex.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
// #define PI 3.14159265
	mlx_t* mlx;

float PI = M_PI , DR = M_PI / 180;
static mlx_image_t* image1;
static mlx_image_t* image2;
static mlx_image_t* image;
double rotation_angle = 0.0;
char **map;
// double cent_y = 190.005414, cent_x = 199.840863;
double cent_y = 200, cent_x = 200;
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
			mlx_put_pixel(image1,  r + (y * 40), f + (x * 40) , ft_pixel(255, 255, 255, 255));
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
			mlx_put_pixel(image1,  r + (y * 40), f + (x * 40) , ft_pixel(0, 0, 0, 255));
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
		mlx_put_pixel(image1,  x0, y0, ft_pixel(255, 0, 0, 255));
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
		mlx_put_pixel(image1,  x0, y0, ft_pixel(255, 0, 0, 255));
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
		mlx_put_pixel(image1,	f, r, ft_pixel(255, 0, 0, 255));
		r++;
	}
	f++;
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
		while(r < 440)
		{
			mlx_put_pixel(image1,  f, r, ft_pixel(96, 96, 96, 255));
			r++;
		}
		f++;
	}

}
int hardcode(int rvy,int rvx)
{
	if (pa <= 2 *PI && pa >= (PI + (PI /2))){
	if ((rvy > 0 && rvy < 560) && (rvx > 0 && rvy < 360))
	{
		if (map[rvy / 40 + 1][rvx / 40] == '1' && map[rvy / 40][rvx / 40 - 1] == '1')
			return (1);
	}}
	else if (pa <= (PI + (PI /2)) && pa > PI){
	if ((rvy > 0 && rvy < 560) && (rvx > 0 && rvy < 360))
	{
		if (map[rvy / 40][rvx / 40 + 1] == '1' && map[rvy / 40 + 1][rvx / 40] == '1')
			return (1);
	}
	}
	else if (pa <= PI && pa >= PI / 2){
	if ((rvy > 0 && rvy < 560) && (rvx > 0 && rvy < 360))
	{
			if (map[rvy / 40][rvx / 40 +1] == '1' && map[rvy / 40 -1][rvx / 40] == '1')
			return (1);

	}}
	else if(pa <= PI/2 && pa >= 0){
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

void hor_line(double *a, double* b, double c)
{
	double rx = 0, ry = 0;
	double  mp=0,mx = 0, my = 0;
	// int dof;
	double xo=0,yo =0 ;
	float ra = c;
	if ( ra > PI)
	{
		ry = (((int)(cent_y / 40))  *40)-1;
		rx = cent_x - ((cent_y - ry) / -(tan(ra)+0.00001));
		yo = -40;
		xo = yo / (tan(ra) + 0.00001);
	}
	if (ra < PI)
	{
		ry = (((int)(cent_y / 40))  *40) + 40;
		rx = cent_x + ((cent_y - ry) / -(tan(ra)+0.00001));
		yo = 40;
		xo = yo / (tan(ra)+0.00001);
	}
	while(1)
	{
		printf("rx %f  ry %f\n",rx, ry );
		if (((int)rx > 560) || ((int)ry > 360))
			break;
		if (((int)rx < 0) || ((int)ry < 0))
			break;
		if (map[(int)(ry / 40)][(int)((rx) / 40)] == '1')
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

void ver_line(double *a, double* b, double c)
{
int mp=0,mx = 0, my = 0,dof;
	double xo=0,yo =0, rvx=0, rvy=0 ;
	double ra = c;

		if ((ra >  PI / 2) || ra < (3*PI/ 2))
		{
			rvx = (((int)(cent_x / 40)) * 40) - 0.0001;
			rvy = cent_y - ((cent_x - rvx) * -tan(ra));
			xo = -40;
			yo = xo * tan(ra);
		}
		if ((ra <  PI / 2) || ra > (3*PI/ 2))
		{
			rvx = (((int)(cent_x / 40)) * 40) + 40;
			rvy = cent_y + ((cent_x - rvx) * - tan(ra));
			xo = 40;
			yo = xo * tan(ra);
		}
		// if(ra == M_PI_2 || ra == (M_PI + M_PI_2))
		// {
		// 	rvy = cent_y;
		// 	rvx = cent_x;
		// }
		while(1)
		{
			printf("rvx %d  rvy %d\n",mx, my );
			if (hardcode(rvy, rvx) == 1)
				break;
			if ((rvx > 560) || (rvy > 360))
				break;
			if ((rvx < 0) || (rvy < 0))
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

void drawray()
{
	printf("---------\n");
	double rx=10000,ry=1000,rvx=10000,rvy =10000, i = 0 ;
	float ra;
	ra = pa - DR *30;
	if(ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	while ( i < 60)
	{
	hor_line(&ry, &rx, ra);
	ver_line(&rvy, &rvx, ra);
	float x1 = 0;
	x1 = sqrt(pow((rx - cent_x), 2) + pow((ry - cent_y), 2));
	float x2 = 0;
	x2 = sqrt(pow((rvx - cent_x), 2) + pow((rvy - cent_y), 2));

	printf("rx %f  ry %f  x1 %f\n",rx, ry, x1 );
	printf("rvx %f  rvy %f  x1 %f\n",rvx, rvy, x2 );
	printf("center x %f  center y %f\n",cent_x, cent_y);
	printf("angle %f\n",pa);

	if (x2 < x1)
		drawline1(cent_x, cent_y, rvx, rvy);
	else if (x2 > x1)
	 drawline1(cent_x, cent_y, rx, ry);
	 i++;
	 ra += DR;
		if(ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
	}
}
void ft_randomize(void *parm)
{
	my_clear();
	rand_map();
	player();
	drawray();
	drawline(cent_x, cent_y, (cent_x + px), (cent_y + py));
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
		pa -= 0.07;
		if (pa <= 0)
			pa+=2*PI;
		px = cos(pa) * 10;
		py = sin(pa) * 10 ;
	}
	if (keydata.key == MLX_KEY_D)
	{
		pa += 0.07;
		if (pa >= 2 * PI)
			pa-=2*PI;
		px = cos(pa) * 10;
		py = sin(pa) * 10;
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
	pa = DR * (90 + 180);
	px = cos(pa) * 40;
	py = sin(pa) * 40;
	// Gotta error check this stuff
	if (!(mlx = mlx_init(600, 400, "MLX42", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
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