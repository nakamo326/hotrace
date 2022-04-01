#ifndef TRIE_H
# define TRIE_H

# include <stdbool.h>
# include <stdlib.h>

// ダブルアレイが高速？
// LOUDS

//まずは配列で

typedef struct s_trie {
	char		*value;
	bool		is_end;
	struct trie	*array[256];
}	t_trie;

t_trie	*generate_node(char *value);

#endif /* TRIE_H */
