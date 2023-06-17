/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:31:35 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/17 16:21:48 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/raycast.h"

void	castrays(t_pinfo *pinfo, t_map *mlx)
{
	float	pos[2];
	int		rays;
	float	distance;
	float	w_height;
	float	r_angle;
	float	rcs[2];

	rays = -1;
	r_angle = pinfo->angle - (FOV / 2);
	while (++rays < WIN_X)
	{
		pos[1] = pinfo->pos_x;
		pos[0] = pinfo->pos_y;
		rcs[1] = sin(convert_to_degree(r_angle)) / RAY_PRESCISION;
		rcs[0] = cos(convert_to_degree(r_angle)) / RAY_PRESCISION;
		while (1)
		{
			pos[0] += rcs[0];
			pos[1] += rcs[1];
			if (mlx->data->map[floor(pos[0])][floor(pos[1])] != '1')
				break ;
		}
		distance = sqrt(pow(pinfo->pos_x - pos[1], 2) + pow(pinfo->pos_y - pos[0], 2));
		w_height = floor((WIN_H / 2) / distance);
		r_angle += (FOV / WIN_X);
	}
}