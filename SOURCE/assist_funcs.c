/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:46:45 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/14 18:53:34 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/parse.h"

void	free_2d_array(char	**ptr)
{
	int	i;

	i = -1;
	if (!ptr)
		return ;
	while (ptr[++i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
	}
	free (ptr);
}
