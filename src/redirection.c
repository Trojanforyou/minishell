/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:30:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/24 14:44:20 by msokolov         ###   ########.fr       */
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
	t_redir	*new;

	new = redir;
	if (redir->type == RE_TRUNC)
}
