/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:46:28 by msokolov          #+#    #+#             */
/*   Updated: 2024/10/16 17:30:59 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
// #include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i > 0)
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i--;
	}
	if (str[i] == (char)c)
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}
// int main(void)
// {
//     const char *str = "Hello, world!";
//     char c = 'o';
//     char *result = ft_strrchr(str, c);
//     if (result) {
//         printf("Последнее вхождение символа '%c': %s\n", c, result);
//     } else {
//         printf("Символ '%c' не найден.\n", c);
//     }
//     return 0;
// }
