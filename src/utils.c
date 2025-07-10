/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:45:36 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/10 19:08:15 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(int argc, char **argv)
{
	int i = 0;
	if (argc < 2)
	{
		write (1, "\n", 1);
		return ;
	}
	if (ft_strncmp(argv[1], "echo", 4))
	{
		while (argv[1][i])
		{
			printf("%c", argv[1][i]);
			i++;
		}
	}
}
void	line_reader(void)
{
	char	*line;
	line = readline(">");
	add_history(line);
	while ((line = readline(">")) != NULL)
	{
		if (*line)
			add_history(line);
	}
	free(line);
}
