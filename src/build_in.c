/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:58:10 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/16 17:31:34 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char ft_pwd(char **argv)
{
    char    buf[BUF_MAX];
    char    *str;
    str = getcwd(buf, sizeof(buf));
    if (!str)
        return (0);
    if (*argv && ft_strncmp(argv[0], "pwd", 4) == 0)
    {
        write(1, str, ft_strlen(str));
        write (1, "\n", 1);
    }
    return (1);
}

void	ft_echo(int argc, char **argv)
{
	int i = 0;
	int	n_flag;

	(void)argc;
	if (argv[0] && ft_strncmp(argv[0], "echo", 5) == 0)
	{
		n_flag = n_case(argv, &i);
		while (argv[i])
		{
			write(1, argv[i], ft_strlen(argv[i]));
			if (argv[i + 1])
				write (1, " ", 1);
			i++;
		}
		if (!n_flag)
			write(1, "\n", 1);
	}
}

int    ft_cd(char **argv)
{
    const char *path;
    int         res;

    if (*argv && ft_strncmp(argv[0], "cd", 3) == 0)
    {
        if (ft_strncmp(argv[0], "cd", 3) == 0 && (!argv[1] || *argv[1] == '~'))
        {
            path = getenv("HOME");
            res = chdir(path);
        }
        else
        {
            path = argv[1];
            res = chdir(path);
            if (res == -1)
                perror("cd");
        }
    }
    return (1);
}

void	ft_env(char **argv, char **env)
{
	if (*argv && ft_strncmp(argv[0], "env", 4) == 0)
	{
		while (*env)
		{
			write (1, *env, ft_strlen(*env));
			write (1, "\n", 1);
			env++;
		}
	}
}
