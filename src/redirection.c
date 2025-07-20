/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:30:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/21 01:07:35 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**tokens(char *line)
{
	int		i;
	int		y;
	char	*token = 0;
	char	**arr;
	char	quote;
	int		start;

	i = -1;
	y = 0;
	arr = malloc(sizeof(char *) *ft_strlen(line));
	while (line[i] == ' ' || line[i] == '\n' || line[i] == '\t' || line[i] == '\v')
		i++;
	while (line[++i])
	{
		start = i;
		if (line[i] == 34)
		{
			quote = line[i];
			// start = i;
			while (line[i] != quote)
				i++;
			i++;
			token = ft_substr(line, start + 1, i - start);
			arr[y++] = token;
			i++;
			continue;
		}
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i])
			i++;
		token = ft_substr(line, start, i - start);
		arr[y++] = token;
	}
	arr[y] = NULL;
	return (arr);
}
