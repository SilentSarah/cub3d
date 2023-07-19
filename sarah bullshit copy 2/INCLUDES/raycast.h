/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassimi <hassimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:35:16 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/19 13:15:10 by hassimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

typedef int32_t	t_rgb;

# define R_X 25
# define R_Y 25
# define WIN_X 640
# define WIN_Y 440
# define RAY_PRESCISION 368

enum e_xy {
	y = 0,
	x = 1,
};

int		get_rgb(t_rgb r, t_rgb g, t_rgb b, float tr);
void 	drawLine(mlx_image_t *image, int x0, int y0, int x1, int y1, int color);
void    mlx_draw_line(mlx_image_t *mlx, int s_x, int s_y, int *e_xy);
void	raycast(t_map *mlx, t_pinfo *pinfo, t_cnf *data);
float	get_dist(float x, float y, float x1, float y1);
void	mlx_clear_screen(mlx_image_t *img);
#endif