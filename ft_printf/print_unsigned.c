/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 08:23:24 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/01 09:09:29 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_with_leftalign(char *string, t_printf *str_info, t_pad *strlen);
static int	print_normal(char *string, t_printf *str_info, t_pad *strlen);

int	print_unsigned(va_list args, t_printf *str_info)
{
	unsigned int	num;
	char			*str_unsigned_num;
	int				length;
	t_pad			strlen;

	num = va_arg(args, unsigned int);
	str_unsigned_num = ft_utoa(num);
	strlen.length = ft_strlen(str_unsigned_num);
	if (str_info->left_align)
		length = print_with_leftalign(str_unsigned_num, str_info, &strlen);
	else
		length = print_normal(str_unsigned_num, str_info, &strlen);
	free(str_unsigned_num);
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
