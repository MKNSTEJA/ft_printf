/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:49:33 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/01 09:09:29 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_specifier(char str, va_list args, t_printf *str_info)
{
	if (str == 'i' || str == 'd')
		return (print_num(args, str_info));
	else if (str == 'c')
		return (print_char(args, str_info));
	else if (str == 's')
		return (print_str(args, str_info));
	else if (str == 'u')
		return (print_unsigned(args, str_info));
	else if (str == 'x' || str == 'X')
		return (print_hexa(args, str, str_info));
	else if (str == '%')
		return (ft_putchar(str));
	else if (str == 'p')
		return (print_pointer(args, str_info));
	return (0);
}
