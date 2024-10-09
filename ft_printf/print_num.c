/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:50:36 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/01 09:09:29 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_with_leftalign(char *string, t_printf *str_info, t_pad *strlen);
static int	print_normal(char *string, t_printf *str_info, t_pad *strlen);

int	print_num(va_list args, t_printf *str_info)
{
	int		num;
	char	*str_num;
	t_pad	strlen;
	int		length;

	num = va_arg(args, int);
	str_num = ft_itoa(num);
	strlen.length = ft_strlen(str_num);
	if (str_info->left_align)
		length = print_with_leftalign(str_num, str_info, &strlen);
	else
		length = print_normal(str_num, str_info, &strlen);
	free(str_num);
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
