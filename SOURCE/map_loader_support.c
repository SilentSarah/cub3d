/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader_support.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:10:04 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/12 20:14:15 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/parse.h"

char	*ft_strchr_set(char *string, char *set)
{
	int	i;

	i = -1;
	while (string[++i])
		if (ft_strchr(set, string[i]))
			return (string + i);
	return (NULL);
}

int compare_cnf_map(char *raw_data)
{
    int         i;
    static char *cnfs[7] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
    char        *cnf;
    char        *map;
    
    i = -1;
    while (cnfs[++i])
    {
        cnf = ft_strnstr(raw_data, cnfs[i], ft_strlen(raw_data));
        map = ft_strchr_set(raw_data, "01");
        if (cnf && map)
		{
			ft_printf(1, "Found cnf %p\nFound Map %p\n", cnf, map);
            break ;
		}
    }
    if (!cnf || !map)
        return (1);
    if (map < cnf)
        return (1);
    return (0);
}
