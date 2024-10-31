/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danperez <danperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:09:21 by danperez          #+#    #+#             */
/*   Updated: 2024/10/31 13:00:03 by danperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	handle_format(char c, va_list args)
{
	int count = 0;

	if (c == 'c')
		count += ft_putchr(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putint(va_arg(args, int));
	else if (c == 'u')
		count += ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (c == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	else if (c == '%')
		count += ft_putchr('%');
	return (count);
}
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_format(format[i], args);
		}
		else
			count += ft_putchr(format[i]);
		i++;
	}
	va_end(args);
	return count;
}
/*
int	main(void)
{
	int	ft_ret, real_ret;

	// Prueba de caracteres individuales
	ft_ret = ft_printf("Caracter: %c\n", 'A');
	real_ret = printf("Caracter: %c\n", 'A');
	printf("ft_printf: %d, printf: %d\n\n", ft_ret, real_ret);

	// Prueba de cadenas
	ft_ret = ft_printf("Cadena: %s\n", "Hola, mundo!");
	real_ret = printf("Cadena: %s\n", "Hola, mundo!");
	printf("ft_printf: %d, printf: %d\n\n", ft_ret, real_ret);

	// Prueba de enteros con signo
	ft_ret = ft_printf("Entero: %d\n", 42);
	real_ret = printf("Entero: %d\n", 42);
	printf("ft_printf: %d, printf: %d\n\n", ft_ret, real_ret);

	// Prueba de enteros negativos
	ft_ret = ft_printf("Entero negativo: %d\n", -42);
	real_ret = printf("Entero negativo: %d\n", -42);
	printf("ft_printf: %d, printf: %d\n\n", ft_ret, real_ret);

	// Prueba de enteros sin signo
	ft_ret = ft_printf("Entero sin signo: %u\n", 3000000000u);
	real_ret = printf("Entero sin signo: %u\n", 3000000000u);
	printf("ft_printf: %d, printf: %d\n\n", ft_ret, real_ret);

	// Prueba de hexadecimal en minúsculas
	ft_ret = ft_printf("Hexadecimal (minúsculas): %x\n", 255);
	real_ret = printf("Hexadecimal (minúsculas): %x\n", 255);
	printf("ft_printf: %d, printf: %d\n\n", ft_ret, real_ret);

	// Prueba de hexadecimal en mayúsculas
	ft_ret = ft_printf("Hexadecimal (mayúsculas): %X\n", 255);
	real_ret = printf("Hexadecimal (mayúsculas): %X\n", 255);
	printf("ft_printf: %d, printf: %d\n\n", ft_ret, real_ret);

	// Prueba de puntero con NULL
	ft_ret = ft_printf("Puntero NULL: %p\n", NULL);
	real_ret = printf("Puntero NULL: %p\n", NULL);
	printf("ft_printf: %d, printf: %d\n\n", ft_ret, real_ret);

	// Prueba de puntero válido
	int num = 42;
	ft_ret = ft_printf("Puntero válido: %p\n", &num);
	real_ret = printf("Puntero válido: %p\n", &num);
	printf("ft_printf: %d, printf: %d\n\n", ft_ret, real_ret);

	// Prueba de porcentaje
	ft_ret = ft_printf("Porcentaje: %%\n");
	real_ret = printf("Porcentaje: %%\n");
	printf("ft_printf: %d, printf: %d\n\n", ft_ret, real_ret);

	return (0);
}
*/