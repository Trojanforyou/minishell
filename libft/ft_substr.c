/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:18:42 by msokolov          #+#    #+#             */
/*   Updated: 2024/10/29 16:04:26 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (start + len > ft_strlen(str))
		len = ft_strlen(str) - start;
	{
		temp = ft_calloc(len +1, sizeof(char));
		if (!temp)
			return (NULL);
		while (i < len)
		{
			temp[i] = str[start + i];
			i++;
		}
	}
	return (temp);
}
