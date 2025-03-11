/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:45:18 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/11 00:25:00 by yabukirento      ###   ########.fr       */
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

static char	*ft_get_next_word(char *s, char c, int *cursor, size_t max_len)
{
	char		*next_word;
	size_t		len;
	int			i;

	if (!s || !cursor)
		return (NULL);

	len = 0;
	i = 0;
	while (s[*cursor] == c && s[*cursor])
		++(*cursor);
	
	while (*cursor + len < max_len && 
		   s[*cursor + len] && 
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

char	**ft_push_swap_split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;
	int		cursor;
	size_t	str_len;

	if (!s)
		return (NULL);
		
	str_len = 0;
	while (s[str_len])
		str_len++;

	i = 0;
	cursor = 0;
	words_count = ft_count_words(s, c);
	if (!words_count)
		exit(1);
		
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 1));
	if (!result_array)
		return (NULL);
		
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
