/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopapon <lopapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:52:49 by codespace         #+#    #+#             */
/*   Updated: 2024/11/13 14:31:21 by lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i--;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return (&((char *)s)[i]);
	return (NULL);
}
