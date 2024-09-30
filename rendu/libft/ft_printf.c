/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:26:50 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/19 11:50:39 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lower(unsigned int decimalnumber)
{
	char	hexnumber[32];
	int		i;
	int		reverse_i;

	i = 0;
	if (decimalnumber == 0)
		return (ft_putchar('0'), 1);
	while (decimalnumber)
	{
		hexnumber[i++] = "0123456789abcdef"[decimalnumber % 16];
		decimalnumber /= 16;
	}
	reverse_i = i - 1;
	while (reverse_i >= 0)
	{
		ft_putchar(hexnumber[reverse_i]);
		reverse_i--;
	}
	return (i);
}

int	upper(unsigned int decimalnumber)
{
	char	hexnumber[32];
	int		i;
	int		reverse_i;
	int		remainder;

	i = 0;
	if (decimalnumber == 0)
		return (ft_putchar('0'), 1);
	while (decimalnumber != 0)
	{
		remainder = decimalnumber % 16;
		if (remainder < 10)
			hexnumber[i++] = 48 + remainder;
		else
			hexnumber[i++] = 55 + remainder;
		decimalnumber /= 16;
	}
	reverse_i = i - 1;
	while (reverse_i >= 0)
	{
		ft_putchar(hexnumber[reverse_i]);
		reverse_i--;
	}
	return (i);
}

int	find_specifier(char myString, va_list args)
{
	int	length;

	length = 0;
	if (myString == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (myString == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (myString == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (myString == 'd' || myString == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (myString == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (myString == 'x')
		length += lower(va_arg(args, unsigned int));
	else if (myString == 'X')
		length += upper(va_arg(args, unsigned int));
	else if (myString == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *myString, ...)
{
	int		length;
	int		i;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, myString);
	while (myString[i] != '\0')
	{
		if (myString[i] == '%')
		{
			length += find_specifier(myString[i + 1], args);
			i++;
		}
		else
			length += ft_putchar(myString[i]);
		i++;
	}
	va_end (args);
	return (length);
}
