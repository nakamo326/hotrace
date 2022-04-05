/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:12:46 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/01 22:13:50 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define STDOUT_BUF 8192

void	ft_putstr(const char *str);
void	putstr_buf(const char *str, bool flush);
void	putstr_flush(void);

#endif
