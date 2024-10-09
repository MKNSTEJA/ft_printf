/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 01:37:55 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/02 08:41:04 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_width(char *string)
{
	char	*str_width;
	int		width;

	str_width = string;
	width = 0;
	while (*str_width && !ft_isdigit(*str_width) && !ft_isalpha(*str_width))
		str_width++;	
	if (ft_isdigit(*str_width))
		width = ft_atoi(str_width);
	return (width);
}
