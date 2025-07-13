/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:45:36 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/14 00:12:13 by msokolov         ###   ########.fr       */
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
		cool_exit(argv);
	}
	free(line);
}

void	cool_exit(char **argv)
{
	if (*argv && ft_strncmp(argv[0], "exit", 5) == 0)
	{
		int arg;
		
		arg = ft_atoi(argv[1]);
		// if (argv[0] && !margv[1])
			write(1, "here", 4);
		if ((arg >= 0 && arg <= 255))
			exit(arg);
		else if ((arg > 255 || arg < 0) && ft_strlen(argv[1]) <= 19)
			exit((unsigned char)ft_atoi(argv[1]));
		else if (ft_strlen(argv[1]) > 19)
			write (1, "yarrak", 7);
	}
}
