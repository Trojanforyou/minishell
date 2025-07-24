/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:18:53 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/24 23:33:08 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * TEMPORARY: This is Temporary parsing function which:
 * Tokenizes input line into array of strings
 * Handles quoted strings preserves spaces inside quotes and splits on whitespace
 * Skips leading whitespace and processes double quotes specially
 * "line" input string to tokenize
 */
// Basically modified split which handles quotes 
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
			i++;
			while (line[i + 1] != quote)
				i++;
			token = ft_substr(line, start + 1 , i - start);
				i++;
			arr[y++] = token;
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
