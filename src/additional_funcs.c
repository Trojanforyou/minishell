/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:09:41 by msokolov          #+#    #+#             */
/*   Updated: 2025/08/10 00:31:14 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"
// void is_build_in(char **argv, char **env, t_env **list, t_redir **redir)
// {
//         if (argv[0] && ft_strncmp(argv[0], "echo", 5) == 0)
//                 ft_echo(argv);
//         if (*argv && ft_strncmp(argv[0], "pwd", 4) == 0)
//                 ft_pwd();
//         if (*argv && ft_strncmp(argv[0], "cd", 3) == 0)
//                 ft_cd(argv);
//         if (*argv && ft_strncmp(argv[0], "env", 4) == 0)
//                 ft_env(env);
//         if (*argv && ft_strncmp(argv[0], "exit", 5) == 0)
//                 cool_exit(argv);
//         if (*argv && ft_strncmp(argv[0], "export", 7) == 0)
//                 ft_export(argv, list);
//         if (*argv && ft_strncmp(argv[0], "unset", 7) == 0)
//                 ft_unset(argv, list);
// }

static	int (*get_easy_builds(char *cmd))(char **argv, char **env)
{
	if (!ft_strncmp(cmd, "echo", 4) && ft_strlen(cmd) == 4)
		return (ft_echo);
	else if (!ft_strncmp(cmd, "pwd", 3) && ft_strlen(cmd) == 3)
		return (ft_pwd);
	else if (!ft_strncmp(cmd, "cd", 2) && ft_strlen(cmd) == 2)
		return (ft_cd);
	else if (!ft_strncmp(cmd, "env", 3) && ft_strlen(cmd) == 3)
		return (ft_env);
	else if (!ft_strncmp(cmd, "exit", 4) && ft_strlen(cmd) == 4)
		return (cool_exit);
	return (NULL);
}

static int (*get_hard_build(char *cmd))(char **argv, t_env **list)
{
	if (!ft_strncmp(cmd, "export", 6) && ft_strlen(cmd) == 6)
		return (ft_export);
	else if (!ft_strncmp(cmd, "unset", 5) && ft_strlen(cmd) == 5)
		return (ft_unset);
	return (NULL);
}

int	build_exe(char **argv, char **env, t_env **list)
{
	int	(*easy_func)(char **argv, char **env);
	int	(*hard_func)(char **argv, t_env	**list);
	int status;
    easy_func = get_easy_builds(argv[0]);
    if (easy_func)
    {
        status = easy_func(argv, env);
        return (status);
    }
    hard_func = get_hard_build(argv[0]);
    if (hard_func)
    {
        status = hard_func(argv, list);
        return (status);
    }
	return (0);	
}