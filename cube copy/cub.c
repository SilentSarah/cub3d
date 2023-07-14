/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:17:11 by hassimi           #+#    #+#             */
/*   Updated: 2023/07/14 09:24:27 by hassimi          ###   ########.fr       */
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

float PI = 3.14159;
static mlx_image_t* image1;
static mlx_image_t* image2;
static mlx_image_t* image;
double rotation_angle = 0.0;
char **map;
float cent_y = 240, cent_x = 240;
float px,py,pa = M_PI_4;


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

void hor_line(int *a, int* b)
{
	int rx = 0, ry = 0;
	int r = 0, mp=0,mx = 0, my = 0,dof;
	int xo=0,yo =0 ;
	float ra;
	float atan= - 1 / tan(ra);
	ra = pa;
		dof = 0;
		if ( ra > PI)
		{
			ry = (((int)cent_y / 40)  *40)- 0.0001;
			printf("ry %d\n",ry);
			rx = cent_x - (((int)cent_y - ry) / tan(ra));
			printf("rx %d\n",rx);
			yo = -40;
			xo = yo / tan(ra);
		}
		if (ra < PI)
		{
			ry = (((int)cent_y / 40)  *40) + 40;
			printf("1ry %d\n",ry);
			rx = cent_x + (((int)cent_y - ry) / -tan(ra));
			printf("1rx %d\n",rx);
			yo = 40;
			xo = yo / tan(ra);
		}
		if ( ra == PI || ra == 0)
		{
			rx = cent_x;
			ry = cent_y;
			dof = 8;
		}
		while(dof < 4)
		{
			mx = rx;
			my = ry;
			printf("x %d  y %d\n",mx, my );
			printf("xo %d  yo %d\n",xo, yo );
			if ((mx > 600) || (my > 400))
				break;
			if ((mx < 0) || (my < 0))
				break;
			if (map[ry / 40][rx / 40] == '1')
					break;
			else
			{
				rx +=xo;
				ry+=yo;
				dof += 1;
			}
		}
			printf("rx %d  ry %d\n",rx, ry );
			printf("%c\n",map[ry / 40][rx / 40]);
			printf("%c\n",map[6][3]);
			*a = ry;
			*b = rx;
}

void ver_line(int *a, int* b)
{
int r = 0, mp=0,mx = 0, my = 0,dof;
	int xo=0,yo =0, rvx=0, rvy=0 ;
	float ra;
	ra = pa;
		dof = 0;
		if ((ra >  PI / 2) && ra < (3*PI/ 2))
		{
			rvx = (((int)cent_x / 40) * 40)- 0.0001;
			printf("rvy %d\n",rvy);
			rvy = cent_y - (((int)cent_x - rvx) * tan(ra));
			printf("rvx %d\n",rvx);
			xo = -40;
			yo = xo * tan(ra);
		}
		if ((ra <  PI / 2) || ra > (3*PI/ 2))
		{
			rvx = (((int)cent_x / 40) * 40) + 40;
			rvy = cent_y + (((int)cent_x - rvx) * -tan(ra));
			xo = 40;
			yo = xo * tan(ra);
		}
		if ( ra == PI || ra == 0)
		{
			rvx = cent_x;
			rvy = cent_y;
			dof = 8;
		}
		while(dof < 4)
		{
			mx = rvx;
			my = rvy;
			printf("x %d  y %d\n",mx, my );
			printf("xo %d  yo %d\n",xo, yo );
			if ((mx > 600) || (my > 400))
				break;
			if ((mx < 0) || (my < 0))
				break;
			if (map[rvy / 40][rvx / 40] == '1')
					break;
			else
			{
				rvx +=xo;
				rvy+=yo;
				dof += 1;
			}
		}
			printf("rvx %d  rvy %d\n",rvx, rvy );
			printf("rvxo %d  rvyo %d\n",xo, yo );
			// printf("%c\n",map[rvy / 40][rvx / 40]);
			// printf("%c\n",map[6][3]);
		*a = rvy;
		*b = rvx;
}

void drawray()
{
	int rx=0,ry=0,rvx=0,rvy =0 ;
	hor_line(&ry, &rx);
	ver_line(&rvy, &rvx);
	int x1 = abs(rx - (int)cent_x);
	int x2 = abs(ry - (int)cent_y);
	int dx1;
	int dx2;
	if (x1 > x2)
		dx1 = x1;
	else
	 dx1 = x2;
	x1 = abs(rvx - (int)cent_x);
	x2 = abs(rvy - (int)cent_y);
	if (x1 > x2)
		dx2 = x1;
	else
	 dx2 = x2;
	if (dx2 < dx1 && (rvx > 0 && rvy > 0))
	// if ((rvx > 0 && rvy > 0))
		drawline1(cent_x, cent_y, rvx, rvy);
	else if (dx2 > dx1 && (rx > 0 && ry > 0))
	 drawline1(cent_x, cent_y, rx, ry);
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
	if (keydata.key == MLX_KEY_ESCAPE)
		exit(0);
	if (keydata.key == MLX_KEY_UP)
	{
		cent_x +=cos(pa)*5;
		cent_y +=sin(pa)*5;

	}
	if (keydata.key == MLX_KEY_DOWN)
	{
		if (map[(int)cent_y /40][(int)cent_x / 40] != '1')
		{
			cent_x -=cos(pa)*5;
			cent_y -=sin(pa)*5;
		}
	}
	if (keydata.key == MLX_KEY_RIGHT)
	{
		cent_y +=cos(-pa)*5;
		cent_x +=sin(-pa)*5;
	}
	if (keydata.key == MLX_KEY_LEFT)
	{
		cent_y -=cos(-pa)*5;
		cent_x -=sin(-pa)*5;
	}
	if (keydata.key == MLX_KEY_A)
	{
		pa -= 0.01;
		if (pa < 0)
			pa+=2*PI;
		px = cos(pa) * 10;
		py = sin(pa) * 10 ;
	}
	if (keydata.key == MLX_KEY_D)
	{
		pa += 0.01;
		if (pa > 2 * PI)
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
	map[1] = "100000001000001";
	map[2] = "100000001000001";
	map[3] = "100000001000001";
	map[4] = "100000000100001";
	map[5] = "100100000000001";
	map[6] = "100100000000001";
	map[7] = "100000001000001";
	map[8] = "100000000000001";
	map[9] = "111111111111111";
	map[10] = 0;
	pa = -0.8;
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