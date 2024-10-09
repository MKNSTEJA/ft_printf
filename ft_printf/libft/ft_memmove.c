/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 07:16:20 by mknsteja          #+#    #+#             */
/*   Updated: 2024/09/24 11:40:24 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t range)
{
	unsigned char	*string_dest;
	unsigned char	*string_src;

	string_dest = (unsigned char *)dest;
	string_src = (unsigned char *)src;
	if (range == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	if ((dest > src) && dest < (src + range))
	{
		while (range--)
		{
			*(string_dest + range) = *(string_src + range);
		}
	}
	else
	{
		while (range--)
		{
			*(string_dest++) = *(string_src++);
		}
	}
	return (dest);
}
