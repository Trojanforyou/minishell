/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:03:45 by msokolov          #+#    #+#             */
/*   Updated: 2024/10/28 19:30:05 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_len(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
	{
		i = 1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*source;
	long	num;

	num = n;
	i = nbr_len(num);
	source = (char *)malloc(sizeof(char) * (nbr_len(num) + 1));
	if (!source)
		return (NULL);
	source[i] = '\0';
	if (num < 0)
	{
		source[0] = '-';
		num = -num;
	}
	if (num == 0)
		source[0] = '0';
	i -= 1;
	while (num > 0)
	{
		source[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (source);
}
