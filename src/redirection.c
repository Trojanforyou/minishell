/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:30:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/25 00:53:02 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_redir_file(char **av)
{
	int	i;

	i = -1;
	while (av[i++])
	{
		if (ft_strncmp(av[i], ">>", 2) == 0 || ft_strncmp(av[i], ">", 1) == 0
		|| ft_strncmp(av[i], "<<", 2) == 0 || ft_strncmp(av[i], "<", 1) == 0)
			return (av[i + 1]);
	}
	return (NULL);
}
int	parse_redirects(char **av, int type)
{
	int	i;

	i = -1;
	while (av[i++])
	{
		if (ft_strncmp(av[i], ">>", 2) == 0)
			type = RE_APPEND;
		else if (ft_strncmp(av[i], ">", 1) == 0)
			type = RE_TRUNC;
		else if (ft_strncmp(av[i], "<<", 2) == 0)
			type = RE_HEREDOC;
		else if (ft_strncmp(av[i], "<", 1) == 0)
			type = RE_INPUT;
	}
	return (type);
}
t_redir	*create_redirect(int type, char **av)
{
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	if (!new)
		return (NULL);
	new->fd = -1;
	new->next = NULL;
	new->type = type;
	new->filename = get_redir_file(av);
	return(new);
}
int	exec_redir(t_redir *redir)
{
	if (redir->type == RE_TRUNC)
	{
		redir->fd = open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (redir->fd == -1)
			perror("open");
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
	else if (redir->type == RE_APPEND)
	{
		redir->fd = open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (redir->fd == -1)
			perror("open");
		dup2(redir->fd, STDOUT_FILENO);
		close(redir->fd);
	}
	return (0);
}
void	build_red(t_redir **redir, char **av)
{
	int	type;
	if (!av || !av[0])  // ← добавить проверку
        return;
	type = parse_redirects(av, 0);
	*redir = create_redirect(type, av);
	if (*redir)
		exec_redir(*redir);
}
