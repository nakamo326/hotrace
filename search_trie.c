#include "trie.h"
#include "get_next_line.h"

#include <string.h>

void	query(t_trie *root, char *key)
{
	t_trie	*ptr;
	int		i;
	int		c;

	ptr = root;
	i = 0;
	while (key[i])
	{
		c = key[i] - ' ';
		if (ptr->array[c] != NULL)
			ptr = ptr->array[c];
		i++;
	}
	if (ptr->is_end == true)
	{
		printf("%s\n", ptr->value);
	}
	else
	{
		printf("%s: Not found.\n", key);
	}
}

void	search_trie(t_trie *root)
{
	int		res;
	char	*key;

	res = 1;
	while (res == SUCCESS)
	{
		res = get_next_line(STDIN_FILENO, &key);
		if (res < 0)
			exit(EXIT_FAILURE);
		if (key[0] == '\0')
			break;
		query(root, key);
		free(key);
	}
}