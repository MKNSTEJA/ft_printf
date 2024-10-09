/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 02:07:09 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/01 09:18:17 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_precision(char *string)
{
	char	*str_precision;
	int		precision;

	str_precision = string;
	precision = -1;
	while (*str_precision != '.' && *str_precision)
		str_precision++;
	if (ft_isdigit(*(++str_precision)))
		precision = ft_atoi(str_precision);
	return (precision);
}
