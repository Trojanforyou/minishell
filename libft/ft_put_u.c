/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:56:38 by msokolov          #+#    #+#             */
/*   Updated: 2024/11/14 14:35:20 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else if (n < 10)
	{
		len += ft_putchar((n % 10) + '0');
	}
	return (len);
}
