/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:33:12 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/20 19:56:43 by hmeftah          ###   ########.fr       */
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

# define EXT_ERROR "Cannot Load the map, Check your map extension\n"
# define LOAD_ERR "Cannot Load the map, Invalid directory or Permissions.\n"
# define READ_ERR "Cannot Read from file.\n"
# define INV_ERR "Cannot load map, Invalid Configuration.\n"

# define WIN_X 640
# define WIN_Y 440

typedef int					t_rgb;

struct s_cnf_data {
	char	*textures[5];
	int		f_value[3];
	int		c_value[3];
	int		*pos;
	char	*cnf_start;
	char	*map_start;
	char	**map;
	char	**cnf;
	bool	outside;
};
typedef struct s_cnf_data	t_cnf;

enum e_texture_values {
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	F = 4,
	C = 5,
};

enum e_rgb_values {
	R = 0,
	G = 1,
	B = 2,
};

typedef struct s_player_info {
	double	pos_x;
	double	pos_y;
	double	angle;
}	t_pinfo;

typedef struct s_texture {
	mlx_texture_t	*t[4];
}	t_texture;

typedef struct s_map_info {
	t_cnf		*data;
	t_pinfo		*pinfo;
	t_texture	*t;
	void		*mlx;
	void		*win;
	float		*lpos;
	int			doom_hight;
	int			doom_width;
	int			map_hight;
	int			map_width;
	double		cent_y;
	double		cent_x;
	double		pa;
	double		py;
	double		px;
	double		dst;
	double		rays[640][3];
	double		map_s;
	mlx_image_t	*image1;
	double		dr;
}	t_map;

typedef struct s_ray{
	double	rx;
	double	ry;
	double	rvx;
	double	rvy;
	double	ra;
	double	x1;
	double	x2;
	double	xo;
	double	yo;
}	t_ray;

typedef struct s_project{
	double	ca;
	int		lineh;
	int		lineo;
	double	ty_step;
	double	ty_off;
	double	ty;
	double	tx;
}	t_project;

typedef struct s_rgba{
	int	blue;
	int	green;
	int	red;
}t_rgba;

typedef struct s_bresenham{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

}t_bresnham;

typedef struct s_bresenham_help{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

}t_bresnham_h;

bool	extract_map_data(t_map *mlx, t_cnf *data);
bool	test_map_walls(t_cnf *data, t_pinfo *pinfo);
bool	parse_map(t_map *mlx, char **map);
void	initialize_mlx(t_map **mlx);
float	*convert_arr(int *pos);
int		raycasting(t_map *doom);
char	*concatinate(char *s1, char *s2);
char	*substring(char *str, unsigned int s, unsigned int size);
int		calculate_char(char *string, char c);
int		compare_cnf_map(char *raw_map, t_cnf *data);
int		load_map(char *file_name, t_cnf *data);
void	free_2d_array(char	**ptr);
bool	extract_values(char *string, int *choice);
void	copy_data(char *res, char *string);
bool	set_texture_data(char **textures, char **cnf);
char	*copy_txt_data(char *origin, char *txt);
bool	set_cnf_data(char **txt, int *floor, int *ceiling, char **cnf);
bool	set_rgb_values(int *choice, char **cnf, char type);
bool	calculate_cnfs(char **cnf);
void	print_map_cnf(t_cnf *data);
bool	find_double_newlines(char *start_map);
float	*convert_arr(int *pos);
char	**add_padding(char **map, t_map *mlx);
int		load_textures(t_map *mlx);
void	ft_hook(mlx_key_data_t keydata, void *param);
void	key_w(t_map *doom);
void	key_down(t_map *doom);
int		ft_pixel(int r, int g, int b, int a);
void	my_clear(t_map *doom);
void	calc_first_ver(double ra, t_ray *hp, t_map *doom);
void	calc_first_hor(double ra, t_ray *hp, t_map *doom);
void	calculating(t_ray *r, t_map *doom);
void	project(t_ray	*r, t_map *doom, int i);
void	projecting2(int i, double ra, double ry, t_map *doom);
void	project2_help(double ra, double ry, t_map *doom, t_project *hb);
void	projecting1(int i, double ra, double ry, t_map *doom);
void	ft_randering(void *parm);
void	where1(t_rgba *rgb, double ra, int c, t_map *doom);
void	where(t_rgba *rgb, double ra, int c, t_map *doom);
void	ver_line(double *a, double *b, double *c, t_map *doom);
void	hor_line(double *a, double *b, double *c, t_map *doom);
int		hardecode_part2(int rvy, int rvx, double ra, t_map *doom);
int		hardcode(int rvy, int rvx, double ra, t_map *doom);
void	drawray(t_map *doom);
void	loading_handler(t_map *mlx, char *dir);
#endif