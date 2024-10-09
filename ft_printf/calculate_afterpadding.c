/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_afterpadding.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 03:15:01 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/02 08:43:56 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calculate_afterpadding(t_printf *str_info, t_pad *strlen, char *string)
{
	(void)string;
	if (str_info->precision >= 0 && str_info->precision < strlen->length)
		strlen->length = str_info->precision;
	if (str_info->width > strlen->length)
		strlen->spaces = str_info->padding - strlen->length;
	else
		strlen->spaces = 0;
	return ;
}
