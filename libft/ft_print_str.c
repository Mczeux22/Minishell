/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:45:59 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/19 15:58:27 by Lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_str(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		(*len) += 6;
		return ;
	}
	while (str[i])
	{
		ft_print_char(str[i], len);
		i++;
	}
}
