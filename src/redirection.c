/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:30:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/07/23 16:36:17 by msokolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_redirects(char *av)
{
	int	i;
	t_redir	list;

	i = 0;

	while (av[i])
	{
		if (ft_strncmp(av[i], ">", 1) == 0)
		{
			if (ft_strncmp(av[i + 1], ">", 1) == 0)
				list.type = RE_APPEND;
			else
				list.type = RE_TRUNC;
		}
		else if (ft_strncmp(av[i], "<", 1) == 0)
		{
			if (ft_strncmp(av[i + 1], "<", 1) == 0)
				list.type = RE_INPUT;
			else
				list.type = RE_HEREDOC;
		}
		i++;
	}
}
t_redir *create_redirect(char *filename)
{
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	if (!new)
		return (1);
	new->fd = -1;
	parse_redirects(filename);
}
