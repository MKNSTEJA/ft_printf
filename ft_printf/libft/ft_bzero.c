/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:07:18 by mknsteja          #+#    #+#             */
/*   Updated: 2024/09/23 14:02:24 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *string, size_t range)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)string;
	i = 0;
	while (i < range)
	{
		*str = 0;
		str++;
		i++;
	}
}
