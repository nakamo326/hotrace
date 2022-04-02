#include "darray.h"
#include "get_next_line.h"

// ascii 32 - 126 --- (code - 32)

void	add_darray(t_darray *arr, char *key, char *value)
{
	(void)arr;
	(void)key;
	(void)value;
	// int		i;
	// int		c;

	// i = 0;
	// ptr = root;
	// while (key[i])
	// {
	// 	c = key[i];
	// 	if (ptr->array[c] != NULL)
	// 		ptr = ptr->array[c];
	// 	else
	// 	{
	// 		new = generate_node(NULL);
	// 		// error
	// 		ptr->array[c] = new;
	// 		ptr = new;
	// 	}
	// 	i++;
	// }
	// ptr->value = value;
	// ptr->is_end = true;
}

void	make_darray(t_darray *arr)
{
	char	*key;
	char	*value;
	int		res;

	arr[0].base = 1;
	arr[0].check = 0;

	res = 1;
	while (res == SUCCESS)
	{
		res = get_next_line(STDIN_FILENO, &key);
		if (res < 0)
			exit(EXIT_FAILURE);
		if (key[0] == '\0')
			break;
		res = get_next_line(STDIN_FILENO, &value);
		if (res < 0)
			exit(EXIT_FAILURE);
		// add_trie(arr, key, value);
		// printf("key: %s, value: %s\n", key, value);
		free(key);
	}
	return ;
}
