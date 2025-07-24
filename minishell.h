/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:47:44 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/24 18:04:46 by msokolov         ###   ########.fr       */
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

typedef enum e_redir_type
{
	RE_INPUT, // <
	RE_TRUNC, // >
	RE_APPEND, // >>
	RE_HEREDOC, // <<
}	t_redir_type;
typedef struct s_env
{
	char			*key;
	char			*value;
	int				exported;
	struct s_env	*next;
	struct s_env	*prev;
	struct t_redir			*link;
}	t_env;

typedef struct s_redir
{
	char			*filename;
	int				type;
	int				fd;
	struct t_redir 		*next;
}	t_redir;

int		arg_counter(char ** argv);
int		n_case(char **argv, int *i);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_cd(char **argv);
int		get_env_len(t_env **list);
int		parse_redirects(char **av, int type);
int		exec_redir(t_redir *redir);

char	ft_pwd(char **argv);
char	**env_to_arr(t_env	**list);
char	**tokens(char *line);
char	*get_redir_file(char **av);

void	line_reader(int argc, char **argv, char **envp, t_env **list, t_redir *link);
void	ft_echo(int argc, char **argv);
void	ft_env(char **argv, char **envp);
void	cool_exit(char **argv);
void	ft_export(char **argv, t_env **list);
void	env_init(t_env **list, char **env);
void	add_in_list(t_env **list, char *key, char *value, int exported);
void    ft_unset(char **argv, t_env **list);
void	build_red(t_redir *redir, char **av);

t_redir	*create_redirect(int type, char **av);

#endif
