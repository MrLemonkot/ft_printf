/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akayle <akayle@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:09:08 by akayle            #+#    #+#             */
/*   Updated: 2022/01/12 18:04:41 by akayle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	check_arg(const char *s, va_list ap, int *len);
int	ft_putchar(char c, int *len);
int	ft_putstr(char *s, int *len);
int	ft_putnbr(int n, int *len);
int	ft_unsigned_putnbr(long long n, int *len);
int	ft_lowhex(unsigned long long int n, int *len);
int	ft_uphex(unsigned long long int n, int *len);
int	ft_pointer(unsigned long long int n, int *len);

#endif
