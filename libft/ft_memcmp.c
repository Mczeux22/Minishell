/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:16 by lopapon           #+#    #+#             */
/*   Updated: 2024/11/12 17:36:57 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*ptr;

	str = (unsigned char *)s1;
	ptr = (unsigned char *)s2;
	while (n)
	{
		if (*str != *ptr)
			return (*str - *ptr);
		str++;
		ptr++;
		n--;
	}
	return (0);
}
