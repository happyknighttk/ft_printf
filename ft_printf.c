/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:31:11 by tkayis            #+#    #+#             */
/*   Updated: 2023/02/21 17:01:44 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion(char c, va_list ag, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(ag, int), len);
	if (c == 's')
		ft_putstr(va_arg(ag, char *), len);
	if (c == 'p')
	{
		ft_putstr("0x", len);
		ft_convert(va_arg(ag, unsigned long long), "0123456789abcdef", len);
	}
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ag, int), len);
	if (c == 'u')
		ft_putu(va_arg(ag, unsigned int), len);
	if (c == 'x')
		ft_convert(va_arg(ag, unsigned int), "0123456789abcdef", len);
	if (c == 'X')
		ft_convert(va_arg(ag, unsigned int), "0123456789ABCDEF", len);
	if (c == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ag;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(ag, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i++;
			conversion(format[i], ag, &len);
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(ag);
	return (len);
}
