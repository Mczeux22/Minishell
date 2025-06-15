/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopapon <lopapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:43:26 by codespace         #+#    #+#             */
/*   Updated: 2024/11/13 14:30:29 by lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char *ft_strnew(size_t size)
{
	char *str;
	
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	bzero(str, size + 1);
	return (str);
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
	char *temp;
	
	temp = 0;
	if (temp)
	{
		temp = memcpy(temp, src, n);
		dest = memcpy(dest, temp, n);
	}
	free(temp);
	return(dest);
}
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*end;
	unsigned char	*start;
	unsigned int	i;

	i = 0;
	end = (unsigned char *)dest;
	start = (unsigned char *)src;
	if (end == NULL && src == NULL)
		return (NULL);
	if (end < start)
	{
		while (i < n)
		{
			end[i] = start[i];
			i++;
		}
	}
	else
	{
		while (i < n--)
		{
			end[n] = start[n];
		}
	}
	return (end);
}
