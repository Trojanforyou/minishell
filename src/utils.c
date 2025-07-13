/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:45:36 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/13 21:58:08 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	n_case(char **argv, int *i)
{
	int j;

	*i = 1;
	while (argv[*i] && argv[*i][0] == '-' && argv[*i][1] == 'n')
	{
		j = 2;
		while (argv[*i][j] == 'n')
			j++;
		if (argv[*i][j] != '\0')
			break ;
		(*i)++;
	}
	return (*i > 1);
}
int	arg_counter(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	line_reader(int argc, char **argv, char **envp)
{
	char	*line;
	while ((line = readline(">")) != NULL)
	{
		if (*line)
		add_history(line);
		argv = ft_split(line, ' ');
		argc = arg_counter(argv);
		ft_echo(argc, argv);
		ft_pwd(argv);
		ft_cd(argv);
		ft_env(argv, envp);
	}
	free(line);
}

void	ft_env(char **argv, char **envp)
{
	if (ft_strncmp(argv[0], "env", 4) == 0)
	{
		while (*envp)
		{
			write (1, *envp, ft_strlen(*envp));
			write (1, "\n", 1);
			envp++;
		}
	}
}
