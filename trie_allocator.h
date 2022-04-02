/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_allocator.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot  <ynakamot@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:32:23 by ynakamot          #+#    #+#             */
/*   Updated: 2022/04/02 17:44:55 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_ALLOCATOR_H
# define TRIE_ALLOCATOR_H

# define N_TRIE 1000

typedef struct s_trie_allocator {
	t_trie						tries[N_TRIE];
	struct s_trie_allocator		*next;
	struct s_trie_allocator		*root;
	size_t						used;
}	t_trie_allocator;

t_trie				*init_root(t_trie_allocator **root);
void				init_trie_allocator(t_trie_allocator *alloc);
t_trie_allocator	*expand_trie_allocator(t_trie_allocator	*current);
t_trie				*trie_allocate(t_trie_allocator *root);
void				deallocate_trie(t_trie_allocator *root);

#endif /* TRIE_ALLOCATOR_H */
