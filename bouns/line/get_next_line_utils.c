/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:43:40 by iezzam            #+#    #+#             */
/*   Updated: 2025/01/03 17:15:25 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*ptr;
	size_t	len;

	len = (ft_strlen(str) + 1);
	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *str, int search)
{
	while (*str)
	{
		if (*str == (char)search)
			return ((char *)str);
		str++;
	}
	if (*str == (char)search)
		return ((char *)str);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
