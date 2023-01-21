/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:09:26 by akayle            #+#    #+#             */
/*   Updated: 2022/01/12 18:07:19 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowhex(unsigned long long int n, int *len)
{
	if (n >= 16)
	{
		ft_lowhex(n / 16, len);
		ft_lowhex(n % 16, len);
	}
	else if (n > 9 && n < 16)
		ft_putchar(n - 10 + 'a', len);
	else
		ft_putchar(n + '0', len);
	return (*len);
}

int	ft_uphex(unsigned long long int n, int *len)
{
	if (n >= 16)
	{
		ft_uphex(n / 16, len);
		ft_uphex(n % 16, len);
	}
	else if (n > 9 && n < 16)
		ft_putchar(n - 10 + 'A', len);
	else
		ft_putchar(n + '0', len);
	return (*len);
}

int	ft_pointer(unsigned long long int n, int *len)
{
	ft_putstr("0x", len);
	ft_lowhex(n, len);
	return (*len);
}
