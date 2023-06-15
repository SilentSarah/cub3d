/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:23:49 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/15 18:20:49 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../ft_malloc/ft_malloc.h"
# include "../MLX42/MLX42.h"
# include <stdlib.h>
# include <fcntl.h>

# define EXT_ERROR "Cannot Load the map, Check your map extension\n"
# define LOAD_ERR "Cannot Load the map, Invalid directory or Permissions.\n"
# define READ_ERR "Cannot Read from file.\n"
# define INV_ERR "Cannot load map, Invalid Configuration.\n"

struct s_cnf_data {
	char	*textures[5];
	int		f_value[3];
	int		c_value[3];
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

char	*concatinate(char *s1, char *s2);
char	*substring(char *str, unsigned int s, unsigned int size);
int		calculate_char(char *string, char c);
int		compare_cnf_map(char *raw_map, t_cnf *data);
int		load_map(char *file_name, t_cnf *data);
bool	extract_map_data(t_cnf *data);
void	free_2d_array(char	**ptr);
bool	extract_map_data(t_cnf *data);
bool	extract_values(char *string, int *choice);
void	copy_data(char *res, char *string);
bool	set_texture_data(char **textures, char **cnf);
char	*copy_txt_data(char *origin, char *txt);
bool	set_cnf_data(char **txt, int *floor, int *ceiling, char **cnf);
bool	set_rgb_values(int *choice, char **cnf, char type);
bool	calculate_cnfs(char **cnf);
void	print_map_cnf(t_cnf *data);
bool	test_map_walls(t_cnf *data);
bool	parse_map(t_cnf *data, char **map);
bool	find_double_newlines(char *start_map);
#endif