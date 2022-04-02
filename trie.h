/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:34:06 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/02 14:57:48 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_H
# define TRIE_H
# define N_CHARTYPES 96
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

struct	s_trie;

typedef struct s_trie {
	bool			is_end;
	struct s_trie	*nexts[N_CHARTYPES];
	char			*value;
}	t_trie;

void	trie_construct(t_trie *trie);
t_trie	*trie_insert(t_trie	*trie, const char *key, const char *value);
char	*trie_retrieve(t_trie *trie, const char *query_str);

#endif
