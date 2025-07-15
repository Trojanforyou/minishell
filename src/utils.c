/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:45:36 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/15 16:46:30 by msokolov         ###   ########.fr       */
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

void	line_reader(int argc, char **argv, char **env, t_env *list)
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
		ft_env(argv, env);
		cool_exit(argv);
		ft_export(argv, &list);
	}
	free(line);
}

void	cool_exit(char **argv)
{
	int arg;
	if (*argv && ft_strncmp(argv[0], "exit", 5) == 0)
	{
		if (!argv[1])
			exit(0);
		arg = ft_atoi(argv[1]);
		if ((*argv[1] < 48 || *argv[1] > 58) && *argv[1] != '-')
		{
			write(2, "exit: numeric argument required\n", 33);
			exit (255);
		}
		if (argv[1] && argv[2])
			write(2, "exit: too many arguments\n", 26);
		else if ((arg >= 255 || arg <= 0 || arg > 0) && ft_strlen(argv[1]) < 19)
			exit((unsigned char)ft_atoi(argv[1]));
		else if (ft_strlen(argv[1]) > 19) // TODO Change strlen function with atoll
		{
			write (2, "exit: numeric argument required\n", 33);
			exit((unsigned char)ft_atoi(argv[1]));
		}
	}
}
int	get_env_len(t_env **list)
{
	int	i;
	t_env	*curr;

	i = 0;
	curr = *list;
	while (curr)
	{
		printf("here\n");
		curr = curr->next;
		i++;
	}
	return (i);
}

