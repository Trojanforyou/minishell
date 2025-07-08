/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:03:03 by msokolov          #+#    #+#             */
/*   Updated: 2024/10/20 15:28:21 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	target;

	i = 0;
	ptr = (unsigned char *)str;
	target = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == target)
		{
			return (&ptr[i]);
		}
		i++;
	}
	return (NULL);
}
// int main()
// {
//     const char str[] = "Hello, world!";
//     char c = 'o';
//     size_t n = 13;
// 	 char *result = ft_memchr(str, c, n);
//     if (result != NULL)
//     {
//         printf("Found '%c' at position: %ld\n", c, result - str);
//     }
//     else
//     {
//         printf("Character '%c' not found in the string.\n", c);
//     }
//     return 0;
// }
