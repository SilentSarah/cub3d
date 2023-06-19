/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:33:12 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/19 16:51:02 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../ft_malloc/ft_malloc.h"
# include "../MLX42/MLX42.h"
# include "parse.h"

# define SPEED 0.1
# define ROT_SPEED 5
# define FOV 60

# define FORWARD 0
# define BACKWARD 1
# define LEFT 2
# define RIGHT 3


typedef struct s_player_info {
	float	pos_x;
	float	pos_y;
	float	angle;
}	t_pinfo;

typedef struct s_map_info {
	t_cnf		*data;
	t_pinfo		*pinfo;
	void		*mlx;
	void		*win;
	float		*lpos;
	mlx_image_t	*image;
}	t_map;

bool	extract_map_data(t_map *mlx, t_cnf *data);
bool	test_map_walls(t_cnf *data, t_pinfo *pinfo);
bool	parse_map(t_map *mlx, char **map);
void	initialize_mlx(t_map **mlx);
void	hook_functions(t_map *mlx);
void	key_handler(void *arg);
float	*convert_arr(int *pos);

#endif