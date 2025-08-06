/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:58:10 by msokolov          #+#    #+#             */
/*   Updated: 2025/08/06 23:46:48 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Implementation of "pwd" command
 * Gets and prints the current working directory.
 * "argv" command arguments array
 */
char ft_pwd()
{
    char    buf[BUF_MAX];
    char    *str;
    str = getcwd(buf, sizeof(buf));
    if (!str)
        return (0);
    write(1, str, ft_strlen(str));
    write (1, "\n", 1);
    return (1);
}

/**
 * Implementation of echo command
 * Prints arguments separated by spaces. Supports -n flag to suppress trailing newline
 * "argc" argument count
 * "argv" command arguments array
 */
void	ft_echo(char **argv)
{
	int i;
	int	n_flag;

    i = 0;
    n_flag = n_case(argv, &i);
    while (argv[i])
    {
        if (get_redir_type(argv[i]))
            i++;
        else
            write(1, argv[i], ft_strlen(argv[i]));
        if (argv[i + 1])
            write (1, " ", 1);
        i++;
    }
    if (!n_flag)
        write(1, "\n", 1);
	}

/**
 * Implementation of cd command.
 * Changes the current working directory. Without arguments or with "~" goes to home
 * "argv" command arguments array
 */
int    ft_cd(char **argv)
{
    const char *path;
    int         res;

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
    return (1);
}

/**
 * Implementation of env command
 * Prints all environment variables in KEY=VALUE format
 * "argv" command arguments array
 * "env" environment variables array
 */
void	ft_env(char **env)
{
    while (*env)
    {
        write (1, *env, ft_strlen(*env));
        write (1, "\n", 1);
        env++;
    }
}
