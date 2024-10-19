/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:16:16 by kmummadi          #+#    #+#             */
/*   Updated: 2024/10/19 15:17:50 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(va_list args)
{
	int		num;
	char	*str_num;
	int		length;

	num = va_arg(args, int);
	str_num = ft_itoa(num);
	length = ft_putstr(str_num);
	free(str_num);
	return (length);
}
