/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danperez <danperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:02:59 by danperez          #+#    #+#             */
/*   Updated: 2024/10/31 12:35:07 by danperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	unsigned long long	addr;
	char				hex[17];
	int					len;
	int					count;

	len = 16;
	addr = (unsigned long long)ptr;
	hex[len] = '\0';
	if (addr == 0)
		return ft_putstr("(nil)");
	while (addr > 0)
	{
		hex[--len] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	count = ft_putstr("0x");
	count += write(1, &hex[len], 16 - len);
	return count;
}
