/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:23:28 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/19 15:58:23 by Lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hexa(long n, int maj)
{
	int		count;
	char	*base;

	count = 1;
	if (maj == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		count = hexa(n / 16, maj);
		n = n % 16;
		count++;
	}
	write(1, &base[n], 1);
	return (count);
}

int	adr_hexa(unsigned long n)
{
	int		count;
	char	*base;

	count = 1;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		count = adr_hexa(n / 16);
		n = n % 16;
		count++;
	}
	write(1, &base[n], 1);
	return (count);
}

void	ft_pointeur(void *arg, int *len)
{
	if (arg != NULL)
	{
		*len += write(1, "0x", 2);
		*len += adr_hexa((unsigned long)arg);
	}
	else
	{
		*len += write(1, "(nil)", 5);
	}
}
