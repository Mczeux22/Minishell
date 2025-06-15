/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:02:40 by codespace         #+#    #+#             */
/*   Updated: 2024/11/17 20:47:21 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)search)
			return (&((char *)str)[i]);
		i++;
	}
	if ((unsigned char)str[i] == (unsigned char)search)
		return (&((char *)str)[i]);
	return (NULL);
}
