/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:31:46 by msokolov          #+#    #+#             */
/*   Updated: 2024/10/26 13:11:39 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (dest > src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char *) dest)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		ft_memcpy (dest, src, len);
	}
	return (dest);
}
