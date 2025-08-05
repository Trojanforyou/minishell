/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:30:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/08/05 23:48:57 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_redir_type(char *str)
{
		if (ft_strncmp(str, ">>", 2) == 0 || ft_strncmp(str, ">", 1) == 0
		|| ft_strncmp(str, "<<", 2) == 0 || ft_strncmp(str, "<", 1) == 0)
			return (1);
		return (0);
}
int	parse_redirects(char *str)
{
	if (ft_strncmp(str, ">>", 2) == 0)
		return (RE_APPEND);
	else if (ft_strncmp(str, "<<", 2) == 0)
		return (RE_HEREDOC);
	else if (ft_strncmp(str, ">", 1) == 0)
		return (RE_TRUNC);
	else if (ft_strncmp(str, "<", 1) == 0)
		return (RE_INPUT);
	return (0);
}
t_redir	*create_redirect(int type, char *filename)
{
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	if (!new)
		return (NULL);
	new->fd = -1;
	new->next = NULL;
	new->type = type;
	new->filename = filename;
	return(new);
}
int	exec_redir(t_redir *redir)
{
	if (redir->type == RE_TRUNC || redir->type == RE_APPEND)
	{
		if (redir->type == RE_TRUNC)
			redir->fd = open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (redir->type == RE_APPEND)
			redir->fd = open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (redir->fd == -1)
			return (perror("open"), -1);
		dup2(redir->fd, STDOUT_FILENO);
		close(redir->fd);
	}
	else if (redir->type == RE_INPUT)
	{
		redir->fd = open(redir->filename, O_RDONLY, 0644);
		if (redir->fd == -1)
			perror("open");
		dup2(redir->fd, STDIN_FILENO);
		close(redir->fd);
	}
	return (0);
}
void	build_red(t_redir **redir, char **av)
{
	int		type;
	int		i;
	char	*filename;

	i = 0;
	while (av[i])
	{
		if (get_redir_type(av[i]))
		{
			type = parse_redirects(av[i]);
			if (ft_strlen(av[i]) > 2)
				printf("Error for more than '>>'");
			filename = av[i + 1];
			*redir = create_redirect(type, filename);
			exec_redir(*redir);
		}
		i++;
	}
}
