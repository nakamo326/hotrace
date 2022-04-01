#include <unistd.h>
#include "trie.h"

int	main(void)
{
	t_trie	*root;

	root = make_trie();
	write(1, "hello world.\n", 13);
	return (0);
}
