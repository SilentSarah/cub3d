/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:08:34 by hmeftah           #+#    #+#             */
/*   Updated: 2023/07/19 14:52:05 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

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
	fd = open(map_dir, O_RDONLY);
	return (fd);
}

char	*read_map(int fd)
{
	int		rd;
	char	buffer[2];
	char	*raw_data;

	raw_data = NULL;
	if (fd < 0)
	{
		ft_printf(2, "%s", LOAD_ERR);
		return (0);
	}
	while (1)
	{
		rd = read(fd, buffer, 1);
		if (rd < 0)
		{
			ft_printf(2, "%s", READ_ERR);
			return (0);
		}
		if (rd == 0)
			break ;
		buffer[1] = '\0';
		raw_data = concatinate(raw_data, buffer);
	}
	return (raw_data);
}

int	load_map(char *file_name, t_cnf *data)
{
	int		fd;
	char	*raw_map;

	(void)data;
	if (check_extension(file_name))
		return (ft_printf(1, "%s", EXT_ERROR));
	fd = open_map(file_name);
	raw_map = read_map(fd);
	if (!raw_map)
		return (ft_printf(1, "%s", READ_ERR));
	if (compare_cnf_map(raw_map, data))
		return (ft_printf(1, "%s", INV_ERR));
	return (0);
}
