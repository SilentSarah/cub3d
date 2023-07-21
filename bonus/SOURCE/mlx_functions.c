/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:27:19 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/21 15:51:10 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	initialize_mlx(t_map **mlx)
{
	*mlx = ft_malloc(sizeof(t_map));
	if (!*mlx)
		return (exit(1));
	(*mlx)->data = ft_malloc(sizeof(t_cnf));
	(*mlx)->pinfo = ft_malloc(sizeof(t_pinfo));
	if (!(*mlx)->data || !(*mlx)->pinfo)
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

void	load_handler(t_map *mlx, char *dir)
{
	if (load_map(dir, mlx->data))
	{
		ft_malloc(-1);
		exit (1);
	}
	if (extract_map_data(mlx, mlx->data))
	{
		free_2d_array(mlx->data->cnf);
		free_2d_array(mlx->data->map);
		ft_malloc(-1);
		exit (1);
	}
	mlx->data->map = add_padding(mlx->data->map, mlx);
	if (load_textures(mlx) || !mlx->data->map)
	{
		free_2d_array(mlx->data->cnf);
		ft_malloc(-1);
		exit (1);
	}
}

int	load_textures(t_map *mlx)
{
	int		i;

	i = -1;
	mlx->t = ft_malloc(sizeof(t_texture));
	if (!mlx->t)
		return (1);
	ft_bzero(mlx->t, sizeof(t_texture));
	ft_printf(1, "[↻] Loading Textures...\n");
	while (++i < 4)
	{
		mlx->t->t[i] = mlx_load_png(mlx->data->textures[i]);
		if (!mlx->t->t[i]
			|| (mlx->t->t[i]->width != 64 || mlx->t->t[i]->height != 64))
		{
			i = -1;
			while (++i < 4)
				if (mlx->t->t[i])
					mlx_delete_texture(mlx->t->t[i]);
			ft_printf(2, "[✘] Invalid Textures, or Invalid Texture Location.\n");
			return (1);
		}
	}
	return (0);
}
