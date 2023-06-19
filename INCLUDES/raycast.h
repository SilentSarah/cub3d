/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:35:16 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/19 15:31:06 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

typedef int32_t	t_rgb;

# define R_X 25
# define R_Y 25
# define WIN_X 1024
# define WIN_Y 1024
# define RAY_PRESCISION 64

enum e_xy {
	y = 0,
	x = 1,
};

bool	draw_2d_map(t_map *mlx);
float	convert_to_degree(int degree);
int		ft_abs(int num);
int		get_rgb(t_rgb r, t_rgb g, t_rgb b, float tr);
void drawLine(mlx_image_t *image, int x0, int y0, int x1, int y1);
void    mlx_draw_line(mlx_image_t *mlx, int s_x, int s_y, int *e_xy);
#endif