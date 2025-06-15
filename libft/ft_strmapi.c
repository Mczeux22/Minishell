/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopapon <lopapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:52:31 by lopapon           #+#    #+#             */
/*   Updated: 2024/11/17 18:50:26 by lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = ft_strnew(ft_strlen(s));
	if (!s)
		return (NULL);
	if (str == NULL)
		return (NULL);
	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			str[i] = f(i, s[i]);
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
