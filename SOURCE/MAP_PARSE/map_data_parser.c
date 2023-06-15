/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:31:12 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/15 16:45:49 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/parse.h"

bool	calculate_cnfs(char **cnf)
{
	int	i;
	int	cnfs[6];

	i = -1;
	ft_bzero(cnfs, 6 * sizeof(int));
	while (cnf[++i])
	{
		if (!ft_strncmp("NO", cnf[i], 2))
			cnfs[NO]++;
		else if (!ft_strncmp("SO", cnf[i], 2))
			cnfs[SO]++;
		else if (!ft_strncmp("WE", cnf[i], 2))
			cnfs[WE]++;
		else if (!ft_strncmp("EA", cnf[i], 2))
			cnfs[EA]++;
		else if (!ft_strncmp("F", cnf[i], 1))
			cnfs[F]++;
		else if (!ft_strncmp("C", cnf[i], 1))
			cnfs[C]++;
	}
	if (cnfs[NO] > 1 || cnfs[NO] <= 0 || cnfs[SO] > 1 || cnfs[SO] <= 0
		|| cnfs[WE] > 1 || cnfs[WE] <= 0 || cnfs[EA] > 1 || cnfs[EA] <= 0
		|| cnfs[F] > 1 || cnfs[F] <= 0 || cnfs[C] > 1 || cnfs[C] <= 0)
		return (1);
	return (0);
}

bool	set_rgb_values(int *choice, char **cnf, char type)
{
	int	i;

	i = -1;
	if (type == 'f')
	{
		while (cnf[++i])
			if (!ft_strncmp(cnf[i], "F", 1))
				if (extract_values(cnf[i], choice))
					return (1);
	}
	else if (type == 'c')
	{
		while (cnf[++i])
			if (!ft_strncmp(cnf[i], "C", 1))
				if (extract_values(cnf[i], choice))
					return (1);
	}
	return (0);
}

bool	set_cnf_data(char **txt, int *floor, int *ceiling, char **cnf)
{
	ft_bzero(floor, 3 * sizeof(int));
	ft_bzero(ceiling, 3 * sizeof(int));
	if (calculate_cnfs(cnf))
		return (1);
	if (set_rgb_values(floor, cnf, 'f'))
		return (1);
	if (set_rgb_values(ceiling, cnf, 'c'))
		return (1);
	if (set_texture_data(txt, cnf))
		return (1);
	return (0);
}

char	*copy_txt_data(char *origin, char *txt)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	txt = ft_malloc(ft_strlen(origin));
	if (!txt)
		return (NULL);
	while (origin[++i])
	{
		if (i == 0 && ft_strchr("NSWE", origin[i])
			&& ft_strchr("OEA", origin[i + 1]))
			i = 2;
		if (origin[i] > 32)
			txt[j++] = origin[i];
	}
	txt[j] = '\0';
	return (txt);
}

bool	set_texture_data(char **textures, char **cnf)
{
	int		i;

	i = -1;
	while (cnf[++i])
	{
		if (!ft_strncmp("NO", cnf[i], 2))
			textures[NO] = copy_txt_data(cnf[i], textures[NO]);
		else if (!ft_strncmp("SO", cnf[i], 2))
			textures[SO] = copy_txt_data(cnf[i], textures[SO]);
		else if (!ft_strncmp("WE", cnf[i], 2))
			textures[WE] = copy_txt_data(cnf[i], textures[WE]);
		else if (!ft_strncmp("EA", cnf[i], 2))
			textures[EA] = copy_txt_data(cnf[i], textures[EA]);
	}
	textures[4] = NULL;
	i = -1;
	while (textures[++i])
		if (!textures[i])
			return (1);
	return (0);
}
