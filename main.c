#include <unistd.h>
#include "trie.h"

int	main(void)
{
	t_trie	*root;

	root = make_trie();
	search_trie(root);
	(void)root;
	return (0);
}
