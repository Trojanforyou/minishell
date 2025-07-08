/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:08:01 by msokolov          #+#    #+#             */
/*   Updated: 2024/11/17 20:36:07 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	i;
	int	len;

	i = n;
	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (i < 0)
	{
		len += ft_putchar('-');
		i = -i;
	}
	if (i > 9)
	{
		len += ft_putnbr(i / 10);
		len += ft_putnbr(i % 10);
	}
	else if (i < 10)
	{
		len += ft_putchar((i % 10) + '0');
	}
	return (len);
}
