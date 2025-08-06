/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:09:41 by msokolov          #+#    #+#             */
/*   Updated: 2025/08/07 00:29:21 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void    is_build_in(char **argv, char **env, t_env **list, t_redir **redir)
{
        build_red(redir, argv);
        if (argv[0] && ft_strncmp(argv[0], "echo", 5) == 0)
		    ft_echo(argv);
        if (*argv && ft_strncmp(argv[0], "pwd", 4) == 0)
	    	ft_pwd();
        if (*argv && ft_strncmp(argv[0], "cd", 3) == 0)
		    ft_cd(argv);
        if (*argv && ft_strncmp(argv[0], "env", 4) == 0)
		    ft_env(env);
        if (*argv && ft_strncmp(argv[0], "exit", 5) == 0)
		    cool_exit(argv);
        if (*argv && ft_strncmp(argv[0], "export", 7) == 0)
		    ft_export(argv, list);
        if (*argv && ft_strncmp(argv[0], "unset", 7) == 0)
		    ft_unset(argv, list);
}
