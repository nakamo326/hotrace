/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:39:41 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/01 22:18:49 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main(void)
{
	t_input_state	i_state;
	char			*line;
	char			*key_str;
	char			*value_str;
	char			*query_result;
	t_trie			trie;

	trie_construct(&trie, '\0');
	i_state = STATE_WAIT_KEY;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (i_state == STATE_WAIT_KEY)
		{
			if (line[0])
			{
				key_str = line;
				i_state = STATE_WAIT_VALUE;
				continue ;
			}
			else
			{
				i_state = STATE_WAIT_QUERY;
			}
		}
		else if (i_state == STATE_WAIT_VALUE)
		{
			value_str = line;
			trie_insert(&trie, key_str, value_str); // TODO: エラーチェック
			i_state = STATE_WAIT_KEY;
			free(key_str);
			continue ;
		}
		else if (i_state == STATE_WAIT_QUERY)
		{
			// Query
			query_result = trie_retrieve(&trie, line);
			if (query_result)
			{
				ft_putstr(query_result);
				ft_putstr("\n");
			}
			else
			{
				ft_putstr(line);
				ft_putstr(": Not found.\n");
			}
		}
		free(line);
	}
}
