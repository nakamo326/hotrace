/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:37:12 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/04 19:33:14 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RD_FILE_H
# define RD_FILE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# define FT_BUFSIZ 4096

typedef struct s_plastic_buffer
{
	char	*body;
	size_t	cap;
	size_t	used;
}	t_plastic_buffer;

void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*rd_read_fd_content(int fd);


#endif
