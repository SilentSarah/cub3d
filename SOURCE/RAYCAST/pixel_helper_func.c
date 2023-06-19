/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_helper_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:10:17 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/19 16:50:15 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/cub3d.h"

float	convert_to_degree(int degree)
{
	return (degree * M_PI / 180);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * (-1));
	return (num);
}

float	*convert_arr(int *pos)
{
	int		i;
	float	*lpos;

	if (!pos)
		return (NULL);
	lpos = ft_malloc(2 * sizeof(float));
	if (!lpos)
		return (NULL);
	ft_bzero(lpos, 2 * sizeof(float));
	i = -1;
	while (++i < 2)
		lpos[i] = pos[i];
	return (lpos);
}