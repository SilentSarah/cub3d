/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:43:53 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/14 18:57:27 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	initialize_mlx(t_map **mlx)
{
	*mlx = ft_malloc(sizeof(t_map));
	if (!*mlx)
		return (exit(1));
	(*mlx)->data = ft_malloc(sizeof(t_cnf));
	if (!(*mlx)->data)
	{
		ft_malloc(-1);
		exit (1);
	}
	(*mlx)->data->cnf = NULL;
	(*mlx)->data->map = NULL;
	(*mlx)->mlx = mlx_init(640, 480, "CUB3D", true);
	if (!(*mlx)->mlx)
	{
		ft_malloc(-1);
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_map	*mlx;

	if (ac == 2)
	{
		initialize_mlx(&mlx);
		if (load_map(av[1], mlx->data))
		{
			ft_malloc(-1);
			exit (1);
		}
		if (extract_map_data(mlx->data))
		{
			ft_printf(2, "%s", INV_ERR);
			free_2d_array(mlx->data->cnf);
			free_2d_array(mlx->data->map);
			ft_malloc(-1);
			exit (1);
		}
		mlx_loop(mlx->mlx);
	}
	return (0);
}
