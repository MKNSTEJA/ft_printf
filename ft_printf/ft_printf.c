/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:11:27 by kmummadi          #+#    #+#             */
/*   Updated: 2024/10/19 16:16:06 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && (ft_isalpha(str[i + 1]) || (str[i + 1] == '%')))
		{
			count += find_specifier(str[++i], args);
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
