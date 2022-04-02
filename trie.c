/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:07:05 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/02 15:01:45 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"
#include "trie_allocator.h"

// head == '\0' is for root.
void	trie_construct(t_trie *trie)
{
	size_t	i;

	i = -1;
	while (++i < N_CHARTYPES)
		trie->nexts[i] = NULL;
	trie->is_end = false;
}

bool	is_acceptable(const char a)
{
	return (' ' <= a && a <= '~');
}

t_trie	*trie_insert(t_trie	*trie, const char *key, const char *value)
{
	char	head;

	while (*key)
	{
		head = *key;
		if (!is_acceptable(head))
			return (NULL);
		if (!(trie->nexts[head - ' ']))
			trie->nexts[head - ' '] = trie_allocate(NULL);
		trie = trie->nexts[head - ' '];
		if (!trie)
			return (NULL);
		++key;
	}
	trie->is_end = true;
	trie->value = (char *)value;
	return (trie);
}

char	*trie_retrieve(t_trie *trie, const char *query_str)
{
	char	head;

	while (*query_str)
	{
		head = *query_str;
		if (!is_acceptable(head))
			return (NULL);
		trie = trie->nexts[head - ' '];
		if (!trie)
			return (NULL);
		++query_str;
	}
	if (trie->is_end)
		return (trie->value);
	else
		return (NULL);
}
