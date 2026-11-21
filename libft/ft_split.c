/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_split.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: fozturk <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/12 15:59:19 by fozturk        #+#    #+#                */
/*   Updated: 2026/10/12 15:59:21 by fozturk        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	isword;

	count = 0;
	isword = 0;
	while (*str)
	{
		if (*str != c && isword == 0)
		{
			count++;
			isword = 1;
		}
		else if (*str == c)
			isword = 0;
		str++;
	}
	return (count);
}

static char	*ft_word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	*ft_free_all(char **result, int j)
{
	while (j > 0)
	{
		j--;
		free(result[j]);
	}
	free(result);
	return (NULL);
}

static int	count_wordone(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str && *str != c)
	{
		count++;
		str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		j;

	if (!s)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[j] = ft_word_dup(s, 0, count_wordone(s, c));
			if (!result[j++])
				return (ft_free_all(result, j));
			s += count_wordone(s, c);
		}
		else
			s++;
	}
	result[j] = NULL;
	return (result);
}
