#include "trie.h"
#include "get_next_line.h"
#include <string.h>

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
		i++;
	}
	return (new);
}

void	add_trie(t_trie *root, char *key, char *value)
{
	int		i;
	int		c;
	t_trie	*ptr;
	t_trie	*new;

	i = 0;
	ptr = root;
	while (key[i])
	{
		c = key[i];
		if (ptr->array[c] != NULL)
			ptr = ptr->array[c];
		else
		{
			new = generate_node(NULL);
			// error
			ptr->array[c] = new;
			ptr = new;
		}
		i++;
	}
	ptr->value = value;
	ptr->is_end = true;
}

t_trie	*make_trie(void)
{
	t_trie	*root;
	char	*key;
	char	*value;
	int		res;

	root = generate_node(NULL);
	res = 1;
	while (res == SUCCESS)
	{
		res = get_next_line(STDIN_FILENO, &key);
		if (res < 0)
			exit(EXIT_FAILURE);
		if (strcmp(key, "") == 0)
			break;
		res = get_next_line(STDIN_FILENO, &value);
		if (res < 0)
			exit(EXIT_FAILURE);
		add_trie(root, key, value);
		// printf("key: %s, value: %s\n", key, value);
		free(key);
	}
	return (root);
}
