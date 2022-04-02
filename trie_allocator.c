/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_allocator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot  <ynakamot@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:34:10 by ynakamot          #+#    #+#             */
/*   Updated: 2022/04/02 17:44:48 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trie.h"
#include "trie_allocator.h"

#include <stdio.h>

void	init_trie_allocator(t_trie_allocator *alloc)
{
	alloc->next = NULL;
	alloc->root = NULL;
	alloc->used = 0;
}

t_trie_allocator	*expand_trie_allocator(t_trie_allocator	*current)
{
	t_trie_allocator	*res;

	res = malloc(sizeof(t_trie_allocator));
	init_trie_allocator(res);
	res->root = current->root;
	current->next = res;
	return (res);
}

t_trie	*trie_allocate(t_trie_allocator *root)
{
	static t_trie_allocator	*current = NULL;
	t_trie_allocator		*new;
	t_trie					*res;

	if (!root && !current)
		return (NULL);
	if (root != NULL)
	{
		current = root;
	}
	else if (current->used == N_TRIE)
	{
		new = expand_trie_allocator(current);
		if (!new)
			return (NULL);
		current = new;
	}
	res = &current->tries[current->used];
	current->used++;
	trie_construct(res);
	return (res);
}

t_trie	*init_root(t_trie_allocator **root)
{
	t_trie	*trie;

	*root = malloc(sizeof(t_trie_allocator));
	if (!*root)
		return (NULL);
	init_trie_allocator(*root);
	trie = trie_allocate(*root);
	return (trie);
}
