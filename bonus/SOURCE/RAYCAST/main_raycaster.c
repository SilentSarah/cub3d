/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_raycaster.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:19:10 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/21 15:59:46 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	drawray(t_map *doom)
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

void	ft_randering(void *parm)
{
	t_map	*doom;

	doom = (t_map *)parm;
	my_clear(doom);
	drawray(doom);
	rand_map(doom);
	player(doom);
	draw_ray_map(doom);
}

// -----------------------------------------------------------------------------
void	assigning(t_map *doom)
{
	doom->cent_x = (doom->pinfo->pos_x * 40) + 20;
	doom->cent_y = (doom->pinfo->pos_y * 40) + 20;
	doom->map_hight = (40 * doom->doom_hight);
	if (doom->map_hight < 440)
		doom->map_hight = 440;
	doom->map_width = (40 * doom->doom_width);
	if (doom->map_width < 640)
		doom->map_width = 640;
	doom->map_s = 0.3;
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

int	raycasting(t_map *doom)
{
	assigning(doom);
	doom->image1 = mlx_new_image(doom->mlx, doom->map_width + 40,
			doom->map_hight + 40);
	mlx_set_cursor_mode(doom->mlx, MLX_MOUSE_HIDDEN);
	mlx_image_to_window(doom->mlx, doom->image1, 0, 0);
	mlx_cursor_hook(doom->mlx, mous_hook, doom);
	mlx_key_hook(doom->mlx, &ft_hook, doom);
	mlx_loop_hook(doom->mlx, ft_randering, doom);
	mlx_loop(doom->mlx);
	mlx_terminate(doom->mlx);
	return (EXIT_SUCCESS);
}
