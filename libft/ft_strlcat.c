/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopapon <lopapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 19:42:01 by codespace         #+#    #+#             */
/*   Updated: 2024/11/17 11:52:36 by lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	i;

	i = 0;
	a = ft_strlen(dest);
	b = ft_strlen(src);
	if (size <= a)
		return (b + size);
	while (a + i < size - 1 && src[i])
	{
		dest[a + i] = src[i];
		i++;
	}
	dest[a + i] = '\0';
	return (a + b);
}
