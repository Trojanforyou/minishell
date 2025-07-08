/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:36:56 by msokolov          #+#    #+#             */
/*   Updated: 2024/12/12 16:04:44 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static int	ft_printf_hex(uintptr_t addr)
{
	int		i;
	char	hex[16];

	i = 0;
	hex[0] = '0';
	hex[1] = '1';
	hex[2] = '2';
	hex[3] = '3';
	hex[4] = '4';
	hex[5] = '5';
	hex[6] = '6';
	hex[7] = '7';
	hex[8] = '8';
	hex[9] = '9';
	hex[10] = 'a';
	hex[11] = 'b';
	hex[12] = 'c';
	hex[13] = 'd';
	hex[14] = 'e';
	hex[15] = 'f';
	if (addr >= 16)
		i = ft_printf_hex(addr / 16);
	write(1, &hex[addr % 16], 1);
	return (i + 1);
}

int	ft_print_p(void *ptr)
{
	int			i;
	int			len;
	uintptr_t	addr;

	i = 0;
	len = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i += 2;
	addr = (uintptr_t)ptr;
	len += ft_printf_hex(addr);
	return (i + len);
}
