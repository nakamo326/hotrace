/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:01:56 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/01 22:16:59 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

void	ft_putstr(const char *str)
{
	const size_t	n = ft_strlen(str);
	ssize_t			res;

	res = write(STDOUT_FILENO, str, n);
	(void)res;
}

void	putstr_buf(const char *str, bool flush)
{
	static char		buf[STDOUT_BUF];
	static size_t	buf_idx = 0;
	ssize_t			res;
	const size_t	n = ft_strlen(str);

	(void)res;
	if (buf_idx + n >= STDOUT_BUF)
	{
		res = write(STDOUT_FILENO, buf, buf_idx);
		buf_idx = 0;
	}
	if (flush == true)
	{
		res = write(STDOUT_FILENO, buf, buf_idx);
		return ;
	}
	while (*str)
	{
		buf[buf_idx] = *str;
		str++;
		buf_idx++;
	}
}
