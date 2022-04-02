/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:54:38 by corvvs            #+#    #+#             */
/*   Updated: 2022/03/04 11:05:11 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	append_to_ring(t_ring *ring, const char *src, size_t n)
{
	size_t			i;
	const size_t	tail = ring->start + ring->used;

	if (n == 0)
	{
		ring->exhausted = true;
		return ;
	}
	i = 0;
	while (i < n)
	{
		ring->buffer[(tail + i) % ring->cap] = src[i];
		i += 1;
	}
	ring->used += n;
	mark_nl_in_ring(ring, ring->used - n);
}

void	mark_nl_in_ring(t_ring *ring, size_t from)
{
	size_t	i;

	i = from;
	while (i < ring->used)
	{
		if (ring->buffer[(ring->start + i) % ring->cap] == '\n')
			break ;
		i += 1;
	}
	ring->first_nl = i;
}

char	*extend_ring(t_ring *ring)
{
	char	*extended;
	size_t	i;
	size_t	old_cap;

	old_cap = ring->cap;
	ring->cap *= 2;
	if (ring->cap == 0)
		ring->cap = (size_t)BUFFER_SIZE;
	extended = malloc(sizeof(char) * ring->cap);
	if (!extended)
	{
		free(ring->buffer);
		return (NULL);
	}
	i = 0;
	while (i < ring->used)
	{
		extended[(ring->start + i) % old_cap]
			= ring->buffer[(ring->start + i) % old_cap];
		i += 1;
	}
	free(ring->buffer);
	return (extended);
}
