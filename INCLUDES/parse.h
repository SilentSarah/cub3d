/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:23:49 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/11 18:05:15 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../ft_malloc/ft_malloc.h"
# include <stdlib.h>
# include "cub3d.h"

# define LOAD_ERR "Cannot Load the map, Invalid directory or Permissions.\n"
# define READ_ERR "Cannot Read from file\n"

typedef struct s_cnf_data {
	char	*textures[4];
	int		f_value[3];
	int		c_value[3];
}	t_cnf;

enum e_texture_values {
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
};

enum e_rgb_values {
	R = 0,
	G = 1,
	B = 2,
};

char	*concatinate(char *s1, char *s2);
char	*substring(char str, unsigned int s, unsigned int size);
#endif