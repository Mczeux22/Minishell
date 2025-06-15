/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lopapon <lopapon@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:44:15 by loicpapon         #+#    #+#             */
/*   Updated: 2025/02/19 15:58:33 by Lopapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_format(char s, va_list args, int *len, int *i)
{
	if (s == 's')
		ft_print_str(va_arg(args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_print_int(va_arg(args, int), len);
	else if (s == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), len);
	else if (s == 'x')
		ft_print_hexa(va_arg(args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_print_hexa(va_arg(args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_pointeur(va_arg(args, void *), len);
	else if (s == 'c')
		ft_print_char(va_arg(args, int), len);
	else if (s == '%')
		ft_print_char('%', len);
	else
		(i)--;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_format(string[i], args, &length, &i);
			i++;
		}
		else
		{
			ft_print_char((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
