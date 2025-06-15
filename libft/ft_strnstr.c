/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopapon <lopapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:42:19 by lopapon           #+#    #+#             */
/*   Updated: 2024/11/13 14:31:17 by lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *pull, const char *find, size_t n)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	if (!*find)
		return ((char *)pull);
	while (pull[i])
	{
		j = 0;
		while (pull[i] == find[j] && pull[i] && i < n)
		{
			i++;
			j++;
		}
		if (!find[j])
			return ((char *)&pull[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}
