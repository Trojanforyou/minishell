/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:14:05 by msokolov          #+#    #+#             */
/*   Updated: 2024/10/28 18:56:01 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*to_find)
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		{
			if (str[i] == to_find[0])
			{
				j = 0;
				while (str[i + j] == to_find[j] && i + j < len)
				{
					if (to_find[j + 1] == '\0')
						return ((char *)&str[i]);
					j++;
				}
			}
			i++;
		}
	}
	return (NULL);
}
