/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:33:17 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/16 15:02:40 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"
#include "../INCLUDES/raycast.h"

float	*convert_arr(int *pos)
{
	int		i;
	float	*lpos;

	if (!pos)
		return (NULL);
	lpos = ft_malloc(2 * sizeof(float));
	if (!lpos)
		return (NULL);
	i = -1;
	while (++i < 2)
		lpos[i] = pos[i];
	return (lpos);
}

void	key_handler(void *arg)
{
	t_map	*mlx;

	mlx = arg;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_W))
	{
		// mlx->data->pos[0] -= 0.1;
	}
}