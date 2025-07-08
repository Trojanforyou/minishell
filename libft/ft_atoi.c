/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:02:17 by msokolov          #+#    #+#             */
/*   Updated: 2024/10/26 13:15:17 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

// int	ft_isdigit(char c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	else
// 		return (0);
// }

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
// int main()
// {
//     const char *str1 = "   --1234";
//     const char *str2 = "42";
//     const char *str3 = "   +987";
//     const char *str4 = "   0";
//     const char *str5 = "  \t  \n   5678  ";
//     printf("ft_atoi(str1) = %d\n", ft_atoi(str1)); // Çıktı: -1234
//     printf("ft_atoi(str2) = %d\n", ft_atoi(str2)); // Çıktı: 42
//     printf("ft_atoi(str3) = %d\n", ft_atoi(str3)); // Çıktı: 987
//     printf("ft_atoi(str4) = %d\n", ft_atoi(str4)); // Çıktı: 0
//     printf("ft_atoi(str5) = %d\n", ft_atoi(str5)); // Çıktı: 5678
//     return 0;
// }
