/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopapon <lopapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:03:48 by lopapon           #+#    #+#             */
/*   Updated: 2024/11/17 17:38:20 by lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_strndup(const char *src, int start, int end)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(end - start + 1);
	if (!dest)
		return (NULL);
	while (start < end)
	{
		dest[i++] = src[start++];
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		tab;
	char	**dest;

	dest = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	i = 0;
	j = 0;
	tab = 0;
	if (!dest)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (j < i)
			dest[tab++] = ft_strndup(s, j, i);
	}
	dest[tab] = NULL;
	return (dest);
}
