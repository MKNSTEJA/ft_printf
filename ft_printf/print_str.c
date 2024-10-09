/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:23:01 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/02 08:44:18 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_with_leftalign(char *string, t_printf *str_info, t_pad *strlen);
static int	print_normal(char *string, t_printf *str_info, t_pad *strlen);

int	print_str(va_list args, t_printf *str_info)
{
	char	*string;
	t_pad	strlen;
	int		len;

	string = va_arg(args, char *);
	printf("Real string: %s\nGiven width: %d\n", string, str_info -> padding);
	if (!string)
	{
		string = "(null)";
		len = ft_putstr(string);
		return (len);
	}
	strlen.length = ft_strlen(string);
	calculate_afterpadding(str_info, &strlen, string);
	printf("Length: %d\nSpaces: %d\n", strlen.length, strlen.spaces);
	if (str_info->left_align)
		len = print_with_leftalign(string, str_info, &strlen);
	else
		len = print_normal(string, str_info, &strlen);
	return (len);
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
