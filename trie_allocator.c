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
	t_trie_allocator *res;

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
		init_trie_allocator(root);
		current = root;
	}
	else if (current->used == N_TRIE - 1)
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

void	free_tries(t_trie *tries)
{
	int i;

	i = 0;
	while (i < N_TRIE)
	{
		free(tries[i].value);
		i++;
	}
}

void	deallocate_trie(t_trie_allocator *alloc)
{
	t_trie_allocator *ptr;

	ptr = alloc;
	while (ptr)
	{
		alloc = ptr->next;
		free_tries(ptr->tries);
		free(ptr);
		ptr = alloc;
	}
}
