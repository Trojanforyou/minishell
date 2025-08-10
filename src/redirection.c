/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msokolov <msokolov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:30:59 by msokolov          #+#    #+#             */
/*   Updated: 2025/08/10 22:49:13 by msokolov         ###   ########.fr       */
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
			(*redir)->execute(*redir);
		}
		i++;
	}
}
