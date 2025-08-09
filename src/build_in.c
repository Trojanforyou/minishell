/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:58:10 by msokolov          #+#    #+#             */
/*   Updated: 2025/08/10 00:38:16 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Implementation of "pwd" command
 * Gets and prints the current working directory.
 * "argv" command arguments array
 */
int ft_pwd(char **argv, char **env)
{
    (void)env;
    char    buf[BUF_MAX];
    *argv = getcwd(buf, sizeof(buf));
    if (!argv)
        return (0);
    write(1, *argv, ft_strlen(*argv));
    write (1, "\n", 1);
    return (1);
}

/**
 * Implementation of echo command
 * Prints arguments separated by spaces. Supports -n flag to suppress trailing newline
 * "argc" argument count
 * "argv" command arguments array
 */
int	ft_echo(char **argv, char **env)
{
	int i;
	int	n_flag;
    (void)env;

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
    return (1);    
}

/**
 * Implementation of cd command.
 * Changes the current working directory. Without arguments or with "~" goes to home
 * "argv" command arguments array
 */
int    ft_cd(char **argv, char **env)
{
    (void)env;
    const char *path;
    int         res;

    if  (!argv[1] || *argv[1] == '~' || ft_strlen(argv[1]) == 0)
    {
        path = getenv("HOME");
        res = chdir(path);
    }
    else
    {
        path = argv[1];
        res = chdir(path);
    }
    if (res == -1)
        return (perror("cd"), 0);
    
    return (1);
}

/**
 * Implementation of env command
 * Prints all environment variables in KEY=VALUE format
 * "argv" command arguments array
 * "env" environment variables array
 */
int	ft_env(char **argv, char **env)
{
    (void)argv;
    while (*env)
    {
        write (1, *env, ft_strlen(*env));
        write (1, "\n", 1);
        env++;
    }
    return (1);
}
