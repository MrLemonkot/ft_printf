/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:09:01 by akayle            #+#    #+#             */
/*   Updated: 2022/01/12 18:00:36 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
	return (*len);
}

int	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
	return (*len);
}

int	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", len);
	else if (n < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(-n, len);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_putchar(n + '0', len);
	return (*len);
}

int	ft_unsigned_putnbr(long long n, int *len)
{
	if (n >= 10)
	{
		ft_unsigned_putnbr(n / 10, len);
		ft_unsigned_putnbr(n % 10, len);
	}
	else
		ft_putchar(n + '0', len);
	return (*len);
}
