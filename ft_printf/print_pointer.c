/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:36:17 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/01 09:09:29 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_with_leftalign(char *string, t_printf *str_info, t_pad *strlen);
static int	print_normal(char *string, t_printf *str_info, t_pad *strlen);

int	print_pointer(va_list args, t_printf *str_info)
{
	unsigned long	num;
	char			*str_ptr;
	int				length;
	t_pad			strlen;
	char			*final_ptr;

	num = (unsigned long)va_arg(args, void *);
	str_ptr = ft_utoa_hex(num, 'x');
	final_ptr = ft_strjoin("0x", str_ptr);
	strlen.length = ft_strlen(final_ptr);
	if (str_info->left_align)
		length = print_with_leftalign(final_ptr, str_info, &strlen);
	else
		length = print_normal(final_ptr, str_info, &strlen);
	free(final_ptr);
	free(str_ptr);
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
