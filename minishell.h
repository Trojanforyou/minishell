/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:47:44 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/15 16:41:01 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# define PATH_MAX 4096
# define BUF_MAX 4096

typedef struct s_env
{
	char	*key;
	char	*value;
	int		exported;
	struct s_env *next;
}	t_env;
int		arg_counter(char ** argv);
void	ft_echo(int argc, char **argv);
void	line_reader(int argc, char **argv, char **envp, t_env *list);
int		ft_pwd(char **argv);
int		n_case(char **argv, int *i);
int		ft_cd(char **argv);
void	ft_env(char **argv, char **envp);
void	cool_exit(char **argv);
int		get_env_len(t_env **list);
char	**env_to_arr(t_env	**list);
void	ft_export(char **argv, t_env **list);
#endif
