/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danperez <danperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:29:24 by danperez          #+#    #+#             */
/*   Updated: 2024/10/31 12:50:17 by danperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(unsigned int n)
{
	char	hex[9];
	int		len;

	len = 8;
	hex[len] = '\0';
	if (n == 0)\
		return ft_putchr('0');
	while (n > 0)
	{
		hex[--len] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return write(1, &hex[len], 8 - len);
}

int	ft_print_hex_upper(unsigned int n)
{
	char	hex[9];
	int		len;

	len = 8;
	hex[len] = '\0';
	if (n == 0)
		return ft_putchr('0');
	while (n > 0)
	{
		hex[--len] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	return write(1, &hex[len], 8 - len);
}
