/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:28:08 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/04 19:33:44 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*us;

	i = -1;
	us = s;
	while (++i < n)
		us[i] = 0;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ud;
	unsigned char	*us;

	i = -1;
	ud = dest;
	us = (unsigned char*)src;
	while (++i < n)
		*ud++ = *us++;
	return (dest);
}
