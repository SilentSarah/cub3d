/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:27:19 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/19 12:07:24 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"
#include "../INCLUDES/raycast.h"

void	initialize_mlx(t_map **mlx)
{
	*mlx = ft_malloc(sizeof(t_map));
	if (!*mlx)
		return (exit(1));
	(*mlx)->data = ft_malloc(sizeof(t_cnf));
	(*mlx)->pinfo = ft_malloc(sizeof(t_pinfo));
	(*mlx)->cam = ft_malloc(sizeof(t_cam));
	if (!(*mlx)->data || !(*mlx)->pinfo || !(*mlx)->cam)
	{
		ft_malloc(-1);
		exit (1);
	}
	(*mlx)->mlx = mlx_init(WIN_X, WIN_Y, "CUB3D", true);
	if (!(*mlx)->mlx)
	{
		ft_malloc(-1);
		exit (1);
	}
	(*mlx)->data->cnf = NULL;
	(*mlx)->data->map = NULL;
}

void	init_player_data(t_pinfo *pinfo, t_cnf *data)
{
	if (data->map[(int)pinfo->pos_y][(int)pinfo->pos_x] == 'N')
		pinfo->angle = 90 * (M_PI / 180);
	else if (data->map[(int)pinfo->pos_y][(int)pinfo->pos_x] == 'E')
		pinfo->angle = 360 * (M_PI / 180);
	else if (data->map[(int)pinfo->pos_y][(int)pinfo->pos_x] == 'S')
		pinfo->angle = 270 * (M_PI / 180);
	else if (data->map[(int)pinfo->pos_y][(int)pinfo->pos_x] == 'W')
		pinfo->angle = 180 * (M_PI / 180);
}

// void	hook_functions(t_map *mlx)
// {

// }
