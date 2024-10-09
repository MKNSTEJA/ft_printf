/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:39:36 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/01 09:09:29 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_with_leftalign(char c, t_printf *str_info, t_pad *strlen);
static int	print_normal(char c, t_printf *str_info, t_pad *strlen);

int	print_char(va_list args, t_printf *str_info)
{
	char	c;
	t_pad	strlen;
	int		len;

	c = (char)va_arg(args, int);
	len = 0;
	strlen.length = 1;
	calculate_afterpadding(str_info, &strlen, NULL);
	if (str_info->left_align)
		len = print_with_leftalign(c, str_info, &strlen);
	else
		len = print_normal(c, str_info, &strlen);
	return (len);
}

static int	print_with_leftalign(char c, t_printf *str_info, t_pad *strlen)
{
	int	i;
	int	length;

	i = 0;
	length = ft_putchar(c);
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

static int	print_normal(char c, t_printf *str_info, t_pad *strlen)
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
	length += ft_putchar(c);
	return (length);
}
