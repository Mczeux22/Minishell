/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:37:16 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/19 15:58:12 by Lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hexa(unsigned int hexa, int *len, char format)
{
	char	tab[25];
	char	*base;
	int		i;

	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	i = 0;
	if (hexa == 0)
	{
		ft_print_char('0', len);
		return ;
	}
	while (hexa != 0)
	{
		tab[i] = base[hexa % 16];
		hexa /= 16;
		i++;
	}
	while (i--)
		ft_print_char(tab[i], len);
}
