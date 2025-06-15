/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:08:41 by codespace         #+#    #+#             */
/*   Updated: 2024/11/12 17:39:14 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int v, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)p)[i] = (unsigned char)v;
		i++;
	}
	return (p);
}
