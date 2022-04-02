/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:54:48 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/02 15:47:13 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif

// - start: リングバッファの先頭の**インデックス**
// - used: リングバッファの使用済み領域の**サイズ**
// - cap: リングバッファの使用可能領域の**サイズ**
// - first_nl: リングバッファの先頭から最初の改行までの文字数(inclusive)
//   - first_nl < cap ならばリングバッファ内に改行がある。そうでなければない。
typedef struct s_ring
{
	char	*buffer;
	size_t	start;
	size_t	used;
	size_t	cap;
	size_t	first_nl;
	bool	exhausted;
}	t_ring;

void	append_to_ring(t_ring *ring, const char *src, size_t n);
void	mark_nl_in_ring(t_ring *ring, size_t from);
char	*extend_ring(t_ring *ring);

char	*get_next_line(int fd);

#endif
