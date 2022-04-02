#include "trie.h"
#include "trie_allocator.h"

void	free_tries(t_trie *tries, size_t used)
{
	size_t	i;

	i = 0;
	while (i < used)
	{
		free(tries[i].value);
		i++;
	}
}

void	deallocate_trie(t_trie_allocator *alloc)
{
	t_trie_allocator	*ptr;

	ptr = alloc;
	while (ptr)
	{
		alloc = ptr->next;
		free_tries(ptr->tries, ptr->used);
		free(ptr);
		ptr = alloc;
	}
}
