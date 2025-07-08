/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:21:58 by msokolov          #+#    #+#             */
/*   Updated: 2024/11/23 18:23:11 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	match_arg(va_list args, const char *s)
{
	int	len;

	len = 0;
	if (*s == 'u')
		len = ft_put_u(va_arg(args, unsigned int));
	if (*s == 'd' || *s == 'i')
		len = ft_putnbr(va_arg(args, int));
	if (*s == 'c')
		len = ft_putchar((char)va_arg(args, int));
	if (*s == 'p')
		len = ft_print_p(va_arg(args, void *));
	if (*s == 'x')
		len = ft_print_x(va_arg(args, unsigned int), 'x');
	if (*s == 'X')
		len = ft_print_x(va_arg(args, unsigned int), 'X');
	if (*s == 's')
		len = ft_print_s(va_arg(args, const char *));
	if (*s == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			len += ft_putchar(str[i]);
		}
		else
		{
			i++;
			len += match_arg(args, &str[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
