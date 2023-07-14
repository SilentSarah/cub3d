/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:17:11 by hassimi           #+#    #+#             */
/*   Updated: 2023/06/01 20:23:45 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx/mlx.h>
#include <stdlib.h>

typedef struct s_void{
	void *a;
	void *b;
	char **f;
	void	*i;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_void;

typedef struct	s_data {
	void	*img;
	char	*addr;

}				t_data;

void	my_mlx_pixel_put(t_void *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int grid(t_void *vo)
{
int y = 0, x = 0;
mlx_clear_window(vo->a, vo->b);

while (x < 640 && y < 440)
{
		my_mlx_pixel_put(vo, x, y, 0xFFFFFF);
	x++;
	if (x == 640)
	{
		x = 0;
		y++;
	}
}
x = 40;
y = 0;
while (y < 440 && x < 640)
{
	my_mlx_pixel_put(vo, x, y, 0x000000);
	y++;
	if (y == 440)
	{
		x+= 40;
		y = 0;
	}
}

y = 40;
x = 0;
while (y < 440 && x < 640)
{
		my_mlx_pixel_put(vo, x, y, 0x000000);
	x++;
	if (x == 640)
	{
		y+= 40;
		x = 0;
	}
}
	mlx_put_image_to_window(vo->a, vo->b, vo->i, 0, 0);
	// usleep(5000);
	return (0);
}
int lol(int key)
{
	printf("%d\n",key);
	if (key == 53)
		exit(0);
	return (0);
}
int main()
{
t_void vo;

vo.f = malloc(sizeof(char * ) * 10);

vo.f[0] = "111111111111111";
vo.f[1] = "100000010000001";
vo.f[2] = "100000000000001";
vo.f[3] = "100000000000001";
vo.f[4] = "100000000000001";
vo.f[5] = "100000000000001";
vo.f[6] = "100000000000001";
vo.f[7] = "100000000000001";
vo.f[8] = "100000000000001";
vo.f[9] = "111111111111111";

vo.a = mlx_init();
vo.b = mlx_new_window(vo.a, 640, 440, "lool");
vo.i = mlx_new_image(vo.a, 1920, 1080);
vo.addr = mlx_get_data_addr(vo.i, &vo.bits_per_pixel, &vo.line_length,
								&vo.endian);
// grid(&vo);
mlx_loop_hook(vo.a, grid, &vo);
mlx_key_hook(vo.b, lol, 0);

mlx_loop(vo.a);


}