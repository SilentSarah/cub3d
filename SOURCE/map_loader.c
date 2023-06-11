/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:08:34 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/11 18:08:13 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/parse.h"

int	check_extension(char *file_name)
{
	char	*extension;

	extension = ft_strnstr(file_name, ".cub", ft_strlen(file_name));
	if (!extension || ft_strncmp(extension, ".cub", ft_strlen(extension)))
		return (1);
	return (0);
}

int	open_map(char *map_dir)
{
	int	fd;

	if (!map_dir)
		return (-1);
	fd = open(map_dir, O_RDONLY, 0644);
	return (fd);
}

char	*read_map(int fd)
{
	char	buffer[2];
	char	*raw_data;

	if (fd < 0)
		return (ft_printf(2, "%s", LOAD_ERR));
	while (1)
	{
		if (read(fd, buffer, 1) < 0)
			return (ft_printf(2, "%s", READ_ERR));
		if (read(fd, buffer, 1) == 0)
			break ;
		buffer[1] = '\0';
		raw_data = concatinate(raw_data, buffer);
	}
	return (raw_data);
}

int	check_arrangement(char	*raw_map)
{
	
}

char	**split_cnf_data(char *raw_map)
{
	char	*s_point;
	char	*split[2];

	
}
