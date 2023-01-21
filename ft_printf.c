/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:09:05 by akayle            #+#    #+#             */
/*   Updated: 2022/01/12 17:16:42 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(const char *s, va_list ap, int *len)
{
	if (*s == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (*s == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if (*s == 'u')
		ft_unsigned_putnbr(va_arg(ap, unsigned int), len);
	else if (*s == 'x')
		ft_lowhex(va_arg(ap, unsigned int), len);
	else if (*s == 'X')
		ft_uphex(va_arg(ap, unsigned int), len);
	else if (*s == 'p')
		ft_pointer(va_arg(ap, unsigned long int), len);
	else if (*s == '%')
		ft_putchar('%', len);
	return (*len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len = check_arg(str, ap, &len);
		}
		else
			ft_putchar(*str, &len);
		str++;
	}
	va_end(ap);
	return (len);
}
