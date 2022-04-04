/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corvvs <corvvs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:40:42 by corvvs            #+#    #+#             */
/*   Updated: 2022/04/04 19:41:55 by corvvs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	skip_delimiter(char const *s, char c, size_t i, bool revert)
{
	if (revert)
	{
		while (s[i] && (s[i] != c))
		{
			i += 1;
		}
		return (i);
	}
	else
	{
		return (i + (s[i] == c));
	}
}

static size_t	count_words(char const *s, char c)
{
	size_t	n_word;
	size_t	i;

	n_word = 0;
	i = 0;
	while (s[i])
	{
		i = skip_delimiter(s, c, i, false);
		if (s[i])
		{
			n_word += 1;
		}
		i = skip_delimiter(s, c, i, true);
	}
	return (n_word);
}

static char	**duplicate_words(size_t word_count, char *s, char c)
{
	char	**splitted_words;
	size_t	n;
	size_t	cut_start;
	size_t	cut_end;

	splitted_words = (char **)malloc((word_count + 1) * sizeof(char *));
	if (splitted_words == NULL)
	{
		return (NULL);
	}
	n = 0;
	cut_end = 0;
	while (n < word_count)
	{
		cut_start = cut_end;
		cut_end = skip_delimiter(s, c, cut_start, true);
		splitted_words[n] = s + cut_start;
		s[cut_end++] = '\0';
		n += 1;
	}
	return (splitted_words);
}

char	**ft_split(char *s, char c)
{
	size_t	word_count;
	char	**splitted;

	if (s == NULL)
	{
		return (NULL);
	}
	word_count = count_words(s, c);
	splitted = duplicate_words(word_count, s, c);
	if (splitted == NULL)
	{
		return (NULL);
	}
	splitted[word_count] = NULL;
	return (splitted);
}
