/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:45:36 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/11 19:50:13 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	arg_counter(char ** argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
void	ft_echo(int argc, char **argv)
{
	int i = 1;
	int j;
	(void)argc;
	if (argv[0] && ft_strncmp(argv[0], "echo", 4) == 0)
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				write(1, &argv[i][j], 1);
				j++;
			}
			i++;
		}
		write (1, "\n", 1);
	}
}

void	line_reader(void)
{
	char	*line;
	int		argc;
	char	**argv;
	while ((line = readline(">")) != NULL)
	{
		if (*line)
		add_history(line);
		argv = ft_split(line, ' ');
		argc = arg_counter(argv);
		ft_echo(argc, argv);
	}
	free(line);
}
