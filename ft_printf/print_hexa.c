/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 09:03:59 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/01 09:09:29 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_with_leftalign(char *string, t_printf *str_info, t_pad *strlen);
static int	print_normal(char *string, t_printf *str_info, t_pad *strlen);

int	print_hexa(va_list args, char format, t_printf *str_info)
{
	unsigned int	num;
	int				length;
	char			*str_hexa;
	t_pad			strlen;

	length = 0;
	num = va_arg(args, unsigned int);
	str_hexa = ft_utoa_hex(num, format);
	strlen.length = ft_strlen(str_hexa);
	calculate_afterpadding(str_info, &strlen, str_hexa);
	if (str_info->left_align)
		length = print_with_leftalign(str_hexa, str_info, &strlen);
	else
		length = print_normal(str_hexa, str_info, &strlen);
	free(str_hexa);
	return (length);
}

static int	print_with_leftalign(char *string, t_printf *str_info, t_pad *strlen)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (i < strlen->length)
		length += ft_putchar(string[i++]);
	if (str_info->zero)
	{
		while (i < (strlen->length + strlen->spaces))
		{
			length += ft_putchar('0');
			i++;
		}
	}
	else
	{
		while (i < (strlen->length + strlen->spaces))
		{
			length += ft_putchar(' ');
			i++;
		}
	}
	return (length);
}

static int	print_normal(char *string, t_printf *str_info, t_pad *strlen)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	if (str_info->zero)
	{
		while (i < (strlen->spaces))
		{
			length += ft_putchar('0');
			i++;
		}
	}
	else
	{
		while (i < (strlen->spaces))
		{
			length += ft_putchar(' ');
			i++;
		}
	}
	i = 0;
	while (i < strlen->length)
		length += ft_putchar(string[i++]);
	return (length);
}
