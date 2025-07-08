/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:34:26 by msokolov          #+#    #+#             */
/*   Updated: 2024/11/14 15:29:44 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static int	hex_convert(uintptr_t arg, char typef)
{
	int	i;
	int	len;

	len = 0;
	i = arg % 16;
	if (arg >= 16)
		len += hex_convert(arg / 16, typef);
	if (i < 10)
		i += 48;
	else
	{
		if (typef == 'X')
			i += 55;
		else
			i += 87;
	}
	len += write(1, &i, 1);
	return (len);
}

int	ft_print_x(unsigned int num, char typef)
{
	int	i;

	i = 0;
	if (!num)
	{
		write(1, "0", 1);
		return (1);
	}
	i += hex_convert(num, typef);
	return (i);
}
