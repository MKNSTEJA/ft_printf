/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 02:41:22 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/02 08:51:49 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_padding(t_printf *str_info, char *string)
{
	char	*str_pad;

	str_pad = string;
	if (*str_pad == '-')
	{
		str_info->left_align = 1;
		str_info->zero = 0;
		str_pad++;
	}
	else
		str_info->left_align = 0;
	if (*str_pad == '0' && !str_info->left_align)
	{
		str_info->zero = 1;
		str_pad++;
	}
	else
		str_info->zero = 0;
	if (ft_isdigit(*str_pad))
		str_info->padding = ft_atoi(str_pad);
	else
		str_info->padding = 0;
	return ;
}
