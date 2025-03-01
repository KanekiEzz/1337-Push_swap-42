/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:36:38 by iezzam            #+#    #+#             */
/*   Updated: 2024/12/31 11:36:52 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static size_t	ft_count_word(const char *str, char c)
{
	size_t	i;
	size_t	kaneki;
	size_t	word;

	i = 0;
	kaneki = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] == c)
			kaneki = 0;
		else if (kaneki == 0)
		{
			kaneki = 1;
			word++;
		}
		i++;
	}
	return (word);
}

static size_t	ft_len_word(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free(char **ptr, int k)
{
	int	i;

	i = 0;
	--k;
	while (i <= k)
		free(ptr[i++]);
	free(ptr);
}

static char	**ft_loop(char **ptr, const char *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	word_len;
	size_t	j;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_len = ft_len_word(&s[i], c);
			ptr[k] = malloc((word_len + 1) * sizeof(char));
			if (!ptr[k])
				return (ft_free(ptr, k), NULL);
			j = 0;
			while (j < word_len)
				ptr[k][j++] = s[i++];
			ptr[k++][j] = '\0';
		}
		else
			i++;
	}
	ptr[k] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	return (ft_loop(ptr, s, c));
}
