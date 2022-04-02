/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:39:57 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/01 22:16:56 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include "trie.h"
# include "trie_allocator.h"
# include "get_next_line.h"

typedef enum e_input_state {
	STATE_DUMMY,
	STATE_WAIT_KEY,
	STATE_WAIT_VALUE,
	STATE_WAIT_QUERY,
	STATE_ERROR,
}	t_input_state;

#endif
