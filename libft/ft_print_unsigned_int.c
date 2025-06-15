/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:46:46 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/19 15:58:30 by Lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_unsigned(unsigned int nb, int *len)
{
	if (nb >= 10)
		ft_print_unsigned(nb / 10, len);
	ft_print_char(nb % 10 + '0', len);
}
