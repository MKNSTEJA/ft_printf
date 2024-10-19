/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:13:39 by kmummadi          #+#    #+#             */
/*   Updated: 2024/10/19 15:39:44 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list args)
{
	unsigned long	num;
	char			*str_ptr;
	int				length;
	char			*final_ptr;

	num = (unsigned long)va_arg(args, void *);
	if (num == 0)
	{
		final_ptr = ft_strdup("0x0");
		length = ft_putstr(final_ptr);
		free(final_ptr);
		return (length);
	}
	str_ptr = ft_utoa_hex(num, 'x');
	final_ptr = ft_strjoin("0x", str_ptr);
	length = ft_putstr(final_ptr);
	free(final_ptr);
	free(str_ptr);
	return (length);
}
