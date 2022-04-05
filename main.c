/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:39:41 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/02 14:57:08 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_input_state	set_key(char **key_str, char *line)
{
	t_input_state	res;

	if (line[0])
	{
		*key_str = line;
		res = STATE_WAIT_VALUE;
	}
	else
	{
		free(line);
		res = STATE_WAIT_QUERY;
	}
	return (res);
}

void	search_query(t_trie *trie, char *query)
{
	char	*res;

	res = trie_retrieve(trie, query);
	if (res)
	{
		putstr_buf(res, false);
		putstr_buf("\n", false);
	}
	else
	{
		putstr_buf(query, false);
		putstr_buf(": Not found.\n", false);
	}
}

t_input_state	add_entry(t_trie *trie, char *key, char *value)
{
	t_trie	*ret;

	ret = trie_insert(trie, key, value);
	if (!ret)
	{
		free(value);
		return (STATE_ERROR);
	}
	free(key);
	return (STATE_WAIT_KEY);
}

// TODO: trie_insert エラーチェック
void	loop(t_trie *trie, t_input_state i_state)
{
	char	*line;
	char	*key_str;

	key_str = NULL;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (i_state == STATE_WAIT_KEY)
		{
			i_state = set_key(&key_str, line);
			continue ;
		}
		else if (i_state == STATE_WAIT_VALUE)
		{
			i_state = add_entry(trie, key_str, line);
			if (i_state == STATE_ERROR)
				break ;
			continue ;
		}
		else if (i_state == STATE_WAIT_QUERY)
			search_query(trie, line);
		free(line);
	}
}

int	main(void)
{
	t_trie				*trie;
	t_trie_allocator	*root;

	trie = init_root(&root);
	if (!trie)
		return (1);
	loop(trie, STATE_WAIT_KEY);
	putstr_flush();
	deallocate_trie(root);
	return (0);
}
