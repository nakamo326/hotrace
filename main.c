#include "darray.h"
#include "trie.h"

#include <stdio.h>

// t_darray g_arr[100000000];


int	main(void)
{
	t_trie	*root;

	root = make_trie();
	search_trie(root);
	// make_darray(g_arr);
	// search_darray(g_arr);
	// printf("%zu\n", sizeof(t_trie));
	return (0);
}
