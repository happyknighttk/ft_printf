/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:31:05 by tkayis            #+#    #+#             */
/*   Updated: 2023/02/24 16:36:49 by tkayis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_convert(unsigned long p, char *base, int *len)
{
	unsigned long	baselen;

	baselen = ft_strlen(base);
	if (p >= baselen)
	{
		ft_convert(p / baselen, base, len);
		ft_convert(p % baselen, base, len);
	}
	else
	{
		ft_putchar(base[p], len);
	}
}
