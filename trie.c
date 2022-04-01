#include "trie.h"

t_trie	*generate_node(char *value)
{
	t_trie	*new;
	int		i;

	new = malloc(sizeof(t_trie));
	if (new == NULL)
	{
		return (NULL);
	}
	new->value = value;
	new->is_end = false;
	i = 0;
	while (i < 256)
	{
		new->array[i] = NULL;
	}
	return (new);
}
