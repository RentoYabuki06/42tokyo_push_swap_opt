/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:45:18 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/11 16:58:24 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*ft_get_next_word(char *s, char c, int *cursor, int max_len)
{
	char	*next_word;
	int		len;
	int		i;

	if (!s || !cursor)
		return (NULL);
	len = 0;
	i = 0;
	while (s[*cursor] == c && s[*cursor])
		++(*cursor);
	while (*cursor + len < max_len && s[*cursor + len] && \
		s[*cursor + len] != c)
		++len;
	next_word = malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while (i < len && s[*cursor])
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

static char	**allocate_and_handle_error(char *s, int words_count)
{
	char	**result_array;

	if (!s)
		return (NULL);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (words_count + 1));
	if (!result_array)
		return (NULL);
	return (result_array);
}

static char	**split_into_words(char *s, char c, int words_count, int str_len)
{
	char	**result_array;
	int		i;
	int		cursor;

	result_array = allocate_and_handle_error(s, words_count);
	if (!result_array)
		return (NULL);
	i = 0;
	cursor = 0;
	while (i < words_count)
	{
		result_array[i] = ft_get_next_word(s, c, &cursor, str_len);
		if (!result_array[i])
		{
			while (--i >= 0)
				free(result_array[i]);
			free(result_array);
			return (NULL);
		}
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}

char	**ft_push_swap_split(char *s, char c)
{
	int		words_count;
	int		str_len;

	str_len = 0;
	while (s && s[str_len])
		str_len++;
	words_count = ft_count_words(s, c);
	return (split_into_words(s, c, words_count, str_len));
}
