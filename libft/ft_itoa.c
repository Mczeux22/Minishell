/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopapon <lopapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:15:39 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/17 18:46:49 by lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

char	*ft_itoa(int n)
{
	char		*tab;
	int			i;
	int			size;
	long int	num;

	num = (long int)n;
	size = ft_size(n);
	tab = ft_strnew(size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	if (num < 0)
	{
		tab[0] = '-';
		num = -num;
		i++;
	}
	if (num == 0)
		tab[i++] = '0';
	while (num != 0)
	{
		tab[size-- - 1] = (num % 10) + '0';
		num /= 10;
	}
	return (tab);
}
