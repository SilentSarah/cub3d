/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:31:35 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/19 15:30:50 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/raycast.h"

// void    mlx_draw_line(mlx_image_t *mlx, float s_x, float s_y, float *e_xy)
// {
//     int i;
// 	int	r_sx[2];
//     int distance;

//     i = -1;

//     // Assigns the difference for later comparaison 
// 	r_sx[0] = e_xy[0] - s_y; // Y
// 	r_sx[1] = e_xy[1] - s_x; // X
	
//     // Checks whether X,Y positions is bigger and Decides which to rely on to calculate the distance
//     if (ft_abs(r_sx[0]) > ft_abs(r_sx[1]))
//         distance = ft_abs(r_sx[0]);
//     else
//         distance =  ft_abs(r_sx[1]);
//     while (++i < distance)
//     {
// 		mlx_put_pixel(mlx, s_x, s_y, get_rgb(255, 0, 0, 1));
//         s_x += (e_xy[1] - s_x) / distance;
//         s_y += (e_xy[0] - s_y) / distance;
//     }
// }

// int *find_steps(int s_x, int s_y, int *e_xy, int *stepsxy)
// {
//     if (s_x < e_xy[1])
//         stepsxy[1] = 1;
//     else
//         stepsxy[1] = -1;
//     if (s_y < e_xy[0])
//         stepsxy[0] = 1;
//     else
//         stepsxy[0] = -1;
//     return (stepsxy);
// }

// void    mlx_draw_line(mlx_image_t *mlx, int s_x, int s_y, int *e_xy)
// {
//     int dxy[2];
//     int stepxy[2];
//     int diff;
// 	int	major;

//     ft_bzero(stepxy, 2 * sizeof(int));
//     find_steps(s_x, s_y, e_xy, stepxy);
//     dxy[1] = abs(e_xy[1] - s_x);
//     dxy[0] = abs(e_xy[0] - s_y);
//     diff = dxy[1] - dxy[0];

//     while (s_x != e_xy[1] || s_y != e_xy[0]) {
//         mlx_put_pixel(mlx, s_x, s_y, get_rgb(255, 0, 0, 1));

//        	major = 2 * diff;
//         if (diff > -dxy[0]) {
//             diff -= dxy[0];
//             s_x += stepxy[1];
//         }
//         if (diff < dxy[1]) {
//             diff += dxy[1];
//             s_y += stepxy[0];
//         }
//     }
// }

void drawLine(mlx_image_t *image, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {
        mlx_put_pixel(image, x0, y0, get_rgb(255, 0, 0, 1));

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

// void	castrays(t_pinfo *pinfo, t_map *mlx)
// {
// 	float	pos[2];
// 	int		rays;
// 	float	distance;
// 	float	w_height;
// 	float	r_angle;
// 	float	rcs[2];

// 	rays = -1;
// 	r_angle = pinfo->angle - (FOV / 2);
// 	while (++rays < WIN_X)
// 	{
// 		pos[1] = pinfo->pos_x;
// 		pos[0] = pinfo->pos_y;
// 		rcs[1] = sin(convert_to_degree(r_angle)) / RAY_PRESCISION;
// 		rcs[0] = cos(convert_to_degree(r_angle)) / RAY_PRESCISION;
// 		while (1)
// 		{
// 			pos[0] += rcs[0];
// 			pos[1] += rcs[1];
// 			if (mlx->data->map[floor(pos[0])][floor(pos[1])] != '1')
// 				break ;
// 		}
// 		distance = sqrt(pow(pinfo->pos_x - pos[1], 2) + pow(pinfo->pos_y - pos[0], 2));
// 		w_height = floor((WIN_H / 2) / distance);
// 		r_angle += (FOV / WIN_X);
// 	}
// }