#ifndef TRIE_H
# define TRIE_H

# include <stdbool.h>
# include <stdlib.h>

// ダブルアレイが高速？
// LOUDS

//まずは配列で

typedef struct s_trie {
	char			*value;
	bool			is_end;
	struct s_trie	*array[256];
}	t_trie;

t_trie	*generate_node(char *value);
t_trie	*make_trie(void);
void	search_trie(t_trie *root);

#endif /* TRIE_H */
