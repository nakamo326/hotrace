/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:04:23 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/02 15:46:14 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read some bytes once from fd, and append them into the ring.
// it will change the ring's attrubutes: used, cap, first_nl and exhausted.
bool	read_to_ring(int fd, t_ring *ring)
{
	char	read_buffer[BUFFER_SIZE];
	ssize_t	read_size;

	read_size = read(fd, read_buffer, (size_t)BUFFER_SIZE);
	if (read_size < 0)
	{
		free(read_buffer);
		return (false);
	}
	if (ring->used + read_size > ring->cap)
		ring->buffer = extend_ring(ring);
	if (!ring->buffer)
	{
		free(read_buffer);
		return (false);
	}
	append_to_ring(ring, read_buffer, read_size);
	return (true);
}

// cut out from start of a ring to first nl / end of the ring.
// it will change the ring's attributes: start, used and first_nl.
char	*extract_from_ring(t_ring *ring)
{
	char			*line;
	const int		ring_has_nl = (ring->first_nl != ring->used);
	const size_t	line_length = ring->first_nl;
	size_t			i;

	if (!ring->buffer || (ring->exhausted && ring->used == 0))
		return (NULL);
	line = malloc(sizeof(char) * (line_length + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < line_length)
	{
		line[i] = ring->buffer[(ring->start + i) % ring->cap];
		i += 1;
	}
	line[line_length] = '\0';
	ring->start = (ring->start + line_length + ring_has_nl) % ring->cap;
	ring->used -= line_length + ring_has_nl;
	mark_nl_in_ring(ring, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_ring	ring;
	char			*line;
	bool			succ_read;

	succ_read = true;
	while (succ_read && !ring.exhausted && ring.first_nl == ring.used)
		succ_read = read_to_ring(fd, &ring);
	if (succ_read)
	{
		line = extract_from_ring(&ring);
		if (line)
			return (line);
		free(line);
	}
	free(ring.buffer);
	ring.buffer = NULL;
	return (NULL);
}
