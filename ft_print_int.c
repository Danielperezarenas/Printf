/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danperez <danperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:13:30 by danperez          #+#    #+#             */
/*   Updated: 2024/10/31 12:53:28 by danperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_putint(int n)
{
	char	*num_str;
	int		len;

	num_str = ft_itoa(n);
	if (!num_str)
		return (0);
	len = ft_putstr(num_str);
	free(num_str);
	return (len);
}

int	ft_print_unsigned_int(unsigned int n)
{
	char	num[10];
	int		len;

	len = 10;
	num[len] = '\0';
	if (n == 0)
		return ft_putchr('0');
	while (n > 0)
	{
		num[--len] = (n % 10) + '0';
		n /= 10;
	}
	return write(1, &num[len], 10 - len);
}
