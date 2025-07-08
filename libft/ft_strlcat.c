/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:01:49 by msokolov          #+#    #+#             */
/*   Updated: 2024/10/20 13:59:25 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	di;
	size_t	si;

	si = ft_strlen(src);
	if (!dest && size == 0)
		return (si);
	d = ft_strlen(dest);
	di = d;
	if (size <= di)
		return (size + si);
	s = 0;
	while (src[s] && d + 1 < size)
	{
		dest[d] = src[s];
		s++;
		d++;
	}
	dest[d] = 0;
	return (di + si);
}
// int main(void)
// {
//     char dest[50] = "Hello, ";
//     const char *src = "world!";
//     size_t size = sizeof(dest);
//     printf("Before ft_strlcat: '%s'\n", dest);
//     size_t result = ft_strlcat(dest, src, size);
//     printf("After ft_strlcat: '%s'\n", dest);
//     printf("Total length after concatenation: %zu\n", result);
//     return 0;
// }
