/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:09:41 by msokolov          #+#    #+#             */
/*   Updated: 2025/08/12 13:34:26 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int (*get_easy_builds(char *cmd))(char **argv, char **env)
{
	if (!cmd || !cmd[0])
		return (NULL);
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
	if (!cmd || !cmd[0])
		return (NULL);
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

	if (!argv || !argv[0])
		return (-1);
	easy_func = get_easy_builds(argv[0]);
    if (easy_func)
		return (easy_func(argv, env));
	hard_func = get_hard_build(argv[0]);
    if (hard_func)
		return (hard_func(argv, list));
	return (-1);
}
