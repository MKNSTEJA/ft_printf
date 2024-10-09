/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:53:20 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/01 12:47:32 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *str, ...)
{
	va_list		args;
	int			count;
	int			i;
	t_printf	str_info;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && !ft_isalpha(str[i + 1]))
		{
			parse_info(&str_info, &str[i + 1]);
			while(!ft_isalpha(str[i++]))
			count += find_specifier(str[i], args, &str_info);
		}
		else if(str[i] == '%' && ft_isalpha(str[i + 1]))
			count += find_specifier(str[++i], args, &str_info);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
