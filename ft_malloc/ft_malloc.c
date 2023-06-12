/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeftah <hmeftah@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:47:23 by hmeftah           #+#    #+#             */
/*   Updated: 2023/06/12 15:59:29 by hmeftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	*allocate_memory(unsigned int size, t_address **addresses)
{
	void		*ptr;
	t_address	*node;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	node = create_node(ptr, size);
	if (node == NULL)
	{
		free(ptr);
		return (NULL);
	}
	add_node_back(addresses, node);
	return (ptr);
}

static void	*free_memory(t_address **addresses)
{
	t_address	*t_node;

	t_node = *addresses;
	if (!*addresses)
		return (NULL);
	while (t_node->next)
	{
		t_node = t_node->next;
		destroy_node(t_node->prev);
	}
	destroy_node(t_node);
	*addresses = NULL;
	return (NULL);
}

/*
- Allocates Memory using malloc(), Returns a pointer on success.
- if the size is bigger or equal to 0 a new pointer will be allocated.
- else the size is less than 0 it will free all pointers held by it.
*/
void	*ft_malloc(long long size)
{
	static t_address	*addresses = NULL;

	if (size >= 0)
		return (allocate_memory(size, &addresses));
	else if (size < 0)
		return (free_memory(&addresses));
	return (NULL);
}
