/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:37:52 by msokolov          #+#    #+#             */
/*   Updated: 2024/10/28 18:57:18 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*source;

	i = 0;
	if (!str || !f)
		return (NULL);
	source = malloc(ft_strlen(str) + 1 * 1);
	if (source == 0)
		return (NULL);
	while (str[i])
	{
		source[i] = (*f)(i, str[i]);
		i++;
	}
	source[i] = 0;
	return (source);
}
