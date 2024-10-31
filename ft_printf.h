/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danperez <danperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:27:37 by danperez          #+#    #+#             */
/*   Updated: 2024/10/31 12:40:10 by danperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putchr(char c);
int	ft_putstr(char *s);
int	ft_putint(int n);
int	ft_print_unsigned_int(unsigned int n);
int ft_print_hex_lower(unsigned int n);
int ft_print_hex_upper(unsigned int n);
int	ft_print_pointer(void *ptr);

#endif