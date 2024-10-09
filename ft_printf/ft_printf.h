/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:27:00 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/01 09:17:30 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

#ifndef T_LIST_DEFINED
#define	T_LIST_DEFINED
typedef struct s_ftprintf_list
{
	int	left_align;
	int	zero;
	int	padding;
	int	width;
	int	precision;
}		t_printf;
#endif

typedef struct pad_list
{
	int	spaces;
	int	length;
}		t_pad;

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printf(char *str, ...);
int		print_char(va_list args, t_printf *str_info);
int		print_num(va_list args, t_printf *str_info);
int		print_str(va_list args, t_printf *str_info);
int		find_specifier(char str, va_list args, t_printf *str_info);
int		print_unsigned(va_list args, t_printf *str_info);
char	*ft_utoa(unsigned int n);
char	*ft_utoa_hex(unsigned int num, char format);
int		print_hexa(va_list args, char format, t_printf *str_info);
int		print_pointer(va_list args, t_printf *str_info);
void	parse_info(t_printf *str_info, char *string);
int		parse_width(char *string);
int		parse_precision(char *string);
void	parse_padding(t_printf *str_info, char *string);
void	calculate_afterpadding(t_printf *str_info, t_pad *strlen, char *string);
#endif
