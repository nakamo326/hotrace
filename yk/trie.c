/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:07:05 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/01 22:22:10 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"

t_trie	*trie_allocate(char head)
{
	t_trie	*trie;

	trie = malloc(sizeof(t_trie));
	if (!trie)
		return (NULL);
	trie_construct(trie, head);
	return (trie);
}

// head == '\0' is for root.
void	trie_construct(t_trie *trie, char head)
{
	ft_bzero(trie->nexts, sizeof(t_trie *) * N_CHARTYPES);
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
			trie->nexts[head - ' '] = trie_allocate(head);
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
