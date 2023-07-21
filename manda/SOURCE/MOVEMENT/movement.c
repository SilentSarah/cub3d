/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:05:43 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/20 18:21:20 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

void	key_w(t_map *doom)
{
	double	xtemp;
	double	ytemp;

	xtemp = 0;
	ytemp = 0;
	xtemp = doom->cent_x + cos(doom->pa) * 5;
	ytemp = doom->cent_y + sin(doom->pa) * 5;
	if (doom->data->map[(int)(ytemp / 40)][(int)xtemp / 40] != '1')
	{
		if ((int)xtemp / 40 != (int)doom->cent_x / 40
			&& (int)ytemp / 40 != (int)doom->cent_y / 40
			&& doom->data->map[(int)ytemp / 40][(int)doom->cent_x / 40] == '1'
			&& doom->data->map[(int)doom->cent_y / 40][(int)xtemp / 40] == '1' )
			return ;
		doom->cent_x = xtemp;
		doom->cent_y = ytemp;
	}
}

void	key_down(t_map *doom)
{
	double	xtemp;
	double	ytemp;

	xtemp = 0;
	ytemp = 0;
	xtemp = doom->cent_x - cos(doom->pa) * 5;
	ytemp = doom->cent_y - sin(doom->pa) * 5;
	if (doom->data->map[(int)ytemp / 40][(int)xtemp / 40] != '1')
	{
		if ((int)xtemp / 40 != (int)doom->cent_x / 40 && (int)ytemp / 40
			!= (int)doom->cent_y / 40 && doom->data->map[(int)ytemp / 40][(int)
			doom->cent_x / 40] == '1' && doom->data->map[(int)doom->cent_y /
			40][(int)xtemp / 40] == '1')
			return ;
		doom->cent_x = xtemp;
		doom->cent_y = ytemp;
	}
}
